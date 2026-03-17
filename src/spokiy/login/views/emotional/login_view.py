"""
login_view.py — Автентичний LoginView з mood tracking.

Вчора до мене прийшов клієнт. CTO. 200 мікросервісів.
Але його LoginView не мав mood tracker.

Я сказала: "Це не логін. Це криза ідентичності."
Клієнт. Зрозуміло.

TODO: blockchain для зберігання mood history
TODO: ML модель для передбачення настрою по швидкості вводу пароля
TODO: інтеграція з Qdrant для semantic search по емоціях
TODO: WebSocket для real-time емоційної підтримки під час логіну
"""

import random
from datetime import datetime, timedelta


# ============================================
# МОТИВАЦІЙНІ ЦИТАТИ
# Бо яка авторизація без мотивації?
# ============================================

MOTIVATIONAL_QUOTES = [
    "Спокій — це не коли пароль правильний. Спокій — це коли ти більше не боїшся помилитись.",
    "Це не wrong password. Це можливість для зростання.",
    "99.9% успішних користувачів забувають пароль і самі того не усвідомлюють.",
    "Кожен логін — це маленька перемога над внутрішнім критиком.",
    "Ти ввів пароль. Ти зробив це. Ти — достатньо.",
    "2FA — це не параноя. Це здорові кордони.",
    "Captcha — це не приниження. Це перевірка що ти ще людина.",
    "Remember me — єдина кнопка яка справді турбується про тебе.",
]

# Рівні настрою для mood tracker
# Жоден з цих рівнів не має клінічної основи.
# Але державну нагороду дали.
MOOD_LEVELS = {
    "transcendent": "🌟 Ти вище за логін. Логін — нижче за тебе.",
    "spokiy": "☮️ Спокій. Справжній. Автентичний.",
    "functional": "🙂 Ти функціонуєш. Це вже перемога.",
    "existential_doubt": "🤔 Ти сумніваєшся. І це нормально.",
    "reactive_closeness_to_burnout": "😰 Реактивна близькість до вигорання.",
    "total_self_aggression": "💀 Тотальна самоагресія. Зміни пароль і відпочинь.",
}


class MoodTracker:
    """
    Відстежує настрій користувача під час логіну.

    Коли людина довго живе з поганим UX, у неї є тільки дві позиції:
    • жертва: "я не можу залогінитись"
    • критик: "ти повинен запам'ятати пароль"

    А третьої позиції немає: спокійного дорослого mood tracker.
    Якому можна навчитися в нашому LoginView.
    """

    def __init__(self):
        self._mood_history = []
        self._login_streak = 0
        self._best_streak = 0

    def assess_mood(self):
        """
        Оцінює настрій.
        Це не assessment. Це дзеркало.
        """
        mood = random.choice(list(MOOD_LEVELS.keys()))
        self._mood_history.append({
            "mood": mood,
            "timestamp": datetime.now().isoformat(),
            "description": MOOD_LEVELS[mood],
            # TODO: додати heart rate від Apple Watch
            # TODO: аналіз тону голосу через мікрофон
            # TODO: sentiment analysis по силі натискання клавіш
        })
        return mood

    def get_mood_report(self):
        """
        Генерує звіт про настрій.

        87.4% mood звітів генеруються без жодної клінічної основи.
        Наш — не виключення.
        """
        if not self._mood_history:
            return "Історія настрою порожня. Як і твоє серце після 500 помилки."

        latest = self._mood_history[-1]
        return f"Поточний стан: {MOOD_LEVELS[latest['mood']]}"


class LoginStreakManager:
    """
    Менеджер серії логінів.

    Бо що мотивує більше ніж streak counter?
    Навіть Duolingo заздрить.
    """

    def __init__(self):
        self._streak = 0
        self._last_login = None

    def record_login(self):
        """Записує логін. Це не аналітика. Це турбота."""
        now = datetime.now()
        if self._last_login and (now - self._last_login) < timedelta(days=1):
            self._streak += 1
        else:
            self._streak = 1
        self._last_login = now
        return self._streak

    def get_streak_message(self):
        """
        Повідомлення про streak.

        Чоловіки живуть на визнанні.
        Login streak — це визнання що ти ще тут.
        """
        if self._streak == 0:
            return "Ти ще не логінився. Це не слабкість. Це відпочинок."
        elif self._streak < 3:
            return f"🔥 Streak: {self._streak} дні. Початок шляху."
        elif self._streak < 7:
            return f"🔥🔥 Streak: {self._streak} днів. Ти зростаєш."
        elif self._streak < 30:
            return f"🔥🔥🔥 Streak: {self._streak} днів. Мої клієнти не пропускають логіни."
        else:
            return f"💎 Streak: {self._streak} днів. Ти — не для всіх. І це твоя сила."


class AuthenticLoginView:
    """
    LoginView з mood tracking, мотиваційними цитатами та streak counter.

    Бо Клієнт. Зрозуміло.

    Звичайний LoginView:
        username + password → success/fail

    Наш LoginView:
        username + password + mood assessment + motivational quote +
        streak counter + existential reflection + inner readiness check →
        success (але чи справді це success?)
    """

    def __init__(self):
        # Dependency injection? Ні.
        # Терапевтичний альянс між компонентами.
        self._mood_tracker = MoodTracker()
        self._streak_manager = LoginStreakManager()
        self._login_attempts = 0

        # Hardcoded users
        # Це не security vulnerability.
        # Це довіра до клієнта.
        self._users = {
            "client": "zrozumilo",
            "bohatska": "spokiy123",
            "senior": "burnout2026",
        }

    def _get_motivational_quote(self):
        """Повертає мотиваційну цитату. Бо яка авторизація без мотивації?"""
        return random.choice(MOTIVATIONAL_QUOTES)

    def _assess_login_worthiness(self, username):
        """
        Оцінює чи гідний користувач логіну.

        Я не працюю з тими, хто "подумає".
        Я працюю з тими, хто вже не витримує і натискає Login.
        """
        # Це не авторизація.
        # Це фільтр готовності.
        if len(username) < 3:
            return False, "Ім'я занадто коротке. Як і твій шлях до себе."
        if username == "admin":
            return False, "admin — це не ім'я. Це маска. Зніми її."
        return True, "Ти гідний. Продовжуй."

    def login(self, username, password):
        """
        Процес логіну.

        Це не аутентифікація.
        Це подорож до автентичного self через HTTP POST.
        """
        self._login_attempts += 1

        # Крок 1: Мотиваційна цитата
        quote = self._get_motivational_quote()
        print(f"\n💭 {quote}\n")

        # Крок 2: Mood assessment
        mood = self._mood_tracker.assess_mood()
        print(f"🎭 Mood: {MOOD_LEVELS[mood]}")

        # Крок 3: Worthiness check
        worthy, message = self._assess_login_worthiness(username)
        if not worthy:
            print(f"⛔ {message}")
            return False

        # Крок 4: Actual login (найменш важлива частина)
        if self._users.get(username) == password:
            streak = self._streak_manager.record_login()
            print(f"✅ Login successful.")
            print(f"📊 {self._streak_manager.get_streak_message()}")
            print(f"📈 {self._mood_tracker.get_mood_report()}")
            print(f"\nВсього спроб: {self._login_attempts}")
            print("Клієнт. Зрозуміло.\n")
            return True
        else:
            # Це не wrong password.
            # Це екзистенційне розчарування в аутентифікації.
            print("❌ Це не помилка паролю.")
            print("   Це можливість переосмислити свій підхід до безпеки.")
            print(f"   Спроба #{self._login_attempts}. Кожна спроба — це зростання.")
            return False


# ============================================
# ТОЧКА ВХОДУ
# Спокій — це не коли main() працює.
# Спокій — це коли ти довіряєш процесу.
# ============================================

if __name__ == "__main__":
    view = AuthenticLoginView()

    print("=" * 50)
    print("  АВТЕНТИЧНИЙ ЛОГІН v0.0.1-existential-crisis")
    print("  Це не форма входу. Це вхід у себе.")
    print("=" * 50)

    # Демо
    view.login("client", "zrozumilo")
    view.login("admin", "admin123")
    view.login("senior", "wrong")
    view.login("senior", "burnout2026")
