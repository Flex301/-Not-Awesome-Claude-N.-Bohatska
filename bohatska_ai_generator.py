#!/usr/bin/env python3
"""
Генератор НОВИХ постів у стилі Богацької через LLM API.

Бере реальні пости з дампу як few-shot приклади,
відправляє в LLM і генерує нові.

Підтримує OpenAI, Gemini, Anthropic та будь-який OpenAI-compatible API.

Env vars:
    BOHATSKA_API_KEY   — API ключ (обов'язково)
    BOHATSKA_BASE_URL  — base URL для API (опціонально, для Gemini/local)
    BOHATSKA_MODEL     — модель (default: gpt-4o-mini)
"""

import argparse
import os
import random
import re
import sys

try:
    from openai import OpenAI
except ImportError:
    print("pip install openai", file=sys.stderr)
    sys.exit(1)


DUMP_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                         "n_bohatska_threads_antipattern.md")

MODES = {
    "spokiy": {
        "description": "Пости у форматі 'Спокій — це не X. Спокій — це Y.'",
        "filter": lambda post: "покій" in post.lower(),
        "instruction": (
            "Згенеруй пост у форматі: 'Спокій — це не [щось очевидне]. "
            "Спокій — це [щось псевдоглибоке].' Одне-два речення максимум."
        ),
    },
    "diagnosis": {
        "description": "Буллет-пойнт 'діагнози' з 3-5 пунктами",
        "filter": lambda post: "•" in post or "часто:" in post.lower(),
        "instruction": (
            "Згенеруй пост-діагноз: незакінчене речення + список з 3-5 пунктів "
            "через '•'. Формат: 'Коли [хтось] [щось відчуває], він часто: • пункт1 • пункт2 ...'"
        ),
    },
    "stats": {
        "description": "Безпідставна статистика без джерел",
        "filter": lambda post: "%" in post or "99" in post,
        "instruction": (
            "Згенеруй пост з вигаданою статистикою. Використовуй конкретні числа "
            "(99.9%, 87%, 73%) без будь-яких джерел. Подай як факт."
        ),
    },
    "client": {
        "description": "Анонімний 'кейс клієнта'",
        "filter": lambda post: "клієнт" in post.lower() or "прийшов" in post.lower(),
        "instruction": (
            "Згенеруй пост-кейс: 'Вчора до мене прийшов клієнт. [Пафосний опис]. "
            "Але він сказав: [драматична цитата].' Завершуй чимось коротким."
        ),
    },
    "guru": {
        "description": "Гуру-позиціювання 'я не для всіх'",
        "filter": lambda post: "я не " in post.lower() and len(post) < 200,
        "instruction": (
            "Згенеруй короткий пост з гуру-позиціюванням: 'Я не для всіх', "
            "'Мої клієнти не торгуються', відсікання 'неготових'. 1-2 речення."
        ),
    },
    "full": {
        "description": "Мікс з кількох паттернів (3-5 постів одним блоком)",
        "filter": None,
        "instruction": (
            "Згенеруй блок з 3-5 постів в різних стилях: одноряддя-мудрість, "
            "діагноз з буллет-пойнтами, кейс клієнта, статистика, гуру-фраза. "
            "Розділяй пости порожнім рядком."
        ),
    },
}

SYSTEM_PROMPT = """\
Ти генератор контенту у стилі Наталі Богацької (@n_bohatska) з Threads.

Стиль:
- Псевдоглибокі одноряддя ("Спокій — це не X. Спокій — це Y.")
- Безпідставна статистика без джерел ("99.9% успішних...")
- Буллет-пойнт "діагнози" (незакінчене речення + 3-5 пунктів через •)
- Псевдотерапевтична термінологія ("реактивна близькість", "тотальна самоагресія")
- Гуру-позиціювання ("Я не для всіх", "Мої клієнти не торгуються")
- Кейси клієнтів ("Вчора прийшов клієнт. Успішний. Але...")
- Thread-розбивка (одна думка = кілька коротких постів)
- Рандомні особисті пости між "терапією"

Тема: успішні чоловіки-підприємці 35-55, кризи стосунків, гроші як мова турботи.

Правила:
- Пиши УКРАЇНСЬКОЮ
- Не додавай пояснень, тегів, хештегів — тільки текст посту
- Тримай тон: серйозний, пафосний, без іронії
- Пости мають виглядати як справжні Threads-пости
"""


def parse_dump(path: str) -> list[str]:
    """Парсить дамп постів з markdown файлу."""
    with open(path, encoding="utf-8") as f:
        content = f.read()

    posts = []
    for block in re.split(r"^---$", content, flags=re.MULTILINE):
        # Видаляємо заголовки ### N
        text = re.sub(r"^###\s*\d+\s*$", "", block, flags=re.MULTILINE).strip()
        if text and len(text) > 10 and not text.startswith("#"):
            posts.append(text)
    return posts


def select_examples(posts: list[str], mode: str, count: int = 10) -> list[str]:
    """Вибирає релевантні приклади для few-shot."""
    mode_cfg = MODES[mode]
    filt = mode_cfg["filter"]

    if filt:
        relevant = [p for p in posts if filt(p)]
    else:
        relevant = posts

    if not relevant:
        relevant = posts

    return random.sample(relevant, min(count, len(relevant)))


def generate(client: OpenAI, model: str, mode: str, examples: list[str],
             temperature: float = 0.9) -> str:
    """Генерує новий пост через LLM."""
    examples_text = "\n---\n".join(examples)
    mode_cfg = MODES[mode]

    messages = [
        {"role": "system", "content": SYSTEM_PROMPT},
        {
            "role": "user",
            "content": (
                f"Ось приклади реальних постів для стилю:\n\n{examples_text}\n\n"
                f"---\n\n{mode_cfg['instruction']}\n\n"
                "Згенеруй НОВИЙ пост (не копіюй приклади)."
            ),
        },
    ]

    response = client.chat.completions.create(
        model=model,
        messages=messages,
        temperature=temperature,
        max_tokens=500,
    )
    return response.choices[0].message.content.strip()


def main():
    parser = argparse.ArgumentParser(
        description="AI генератор нових постів у стилі Богацької",
    )
    parser.add_argument(
        "--mode",
        choices=list(MODES.keys()),
        default="full",
        help="Режим генерації (default: full)",
    )
    parser.add_argument(
        "--count", type=int, default=1,
        help="Кількість постів",
    )
    parser.add_argument(
        "--model", default=None,
        help="Модель (default: env BOHATSKA_MODEL або gpt-4o-mini)",
    )
    parser.add_argument(
        "--temperature", type=float, default=0.9,
        help="Temperature для генерації (default: 0.9)",
    )
    parser.add_argument(
        "--examples", type=int, default=10,
        help="Кількість прикладів з дампу для few-shot (default: 10)",
    )
    parser.add_argument(
        "--dump", default=DUMP_PATH,
        help="Шлях до файлу з дампом постів",
    )
    parser.add_argument(
        "--list-modes", action="store_true",
        help="Показати доступні режими",
    )
    args = parser.parse_args()

    if args.list_modes:
        for name, cfg in MODES.items():
            print(f"  {name:12s} — {cfg['description']}")
        return 0

    api_key = os.environ.get("BOHATSKA_API_KEY")
    if not api_key:
        print("Встанови BOHATSKA_API_KEY (OpenAI, Gemini, або інший API ключ)",
              file=sys.stderr)
        return 1

    base_url = os.environ.get("BOHATSKA_BASE_URL")
    model = args.model or os.environ.get("BOHATSKA_MODEL", "gpt-4o-mini")

    client_kwargs = {"api_key": api_key}
    if base_url:
        client_kwargs["base_url"] = base_url

    client = OpenAI(**client_kwargs)

    if not os.path.exists(args.dump):
        print(f"Дамп не знайдено: {args.dump}", file=sys.stderr)
        return 1

    posts = parse_dump(args.dump)
    if not posts:
        print("Дамп порожній або не парситься", file=sys.stderr)
        return 1

    for i in range(args.count):
        if i > 0:
            print("\n" + "─" * 40 + "\n")

        examples = select_examples(posts, args.mode, args.examples)
        result = generate(client, model, args.mode, examples, args.temperature)
        print(result)

    return 0


if __name__ == "__main__":
    sys.exit(main())
