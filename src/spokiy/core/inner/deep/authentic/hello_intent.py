"""
hello_intent.py — Визначення наміру привітання.

Перш ніж сказати "hello", потрібно зрозуміти:
а чи справді ти хочеш привітатись?
Чи це реактивна близькість до stdout?

Клієнт. Зрозуміло.
"""


class HelloIntentDiscoveryFacilitator:
    """
    Фасилітатор відкриття наміру привітання.

    99.9% розробників пишуть print("hello") без усвідомлення
    свого справжнього наміру. Цей клас допомагає.
    """

    def __init__(self):
        # Спокій — це не коли __init__ має параметри.
        # Спокій — це коли self достатньо.
        self._intent_discovered = False
        self._inner_readiness = 0.0
        self._existential_doubt_level = 0.73  # 73% — базовий рівень сумніву

    def facilitate_intent_discovery(self):
        """
        Це не метод.
        Це перший крок.
        """
        # Замість того, щоб піти в емоційний контакт з stdout,
        # він іде в:
        # • рефлексію
        # • ще більше абстракцій
        # • inner readiness check
        self._inner_readiness += 0.1
        if self._inner_readiness >= self._existential_doubt_level:
            self._intent_discovered = True
        return self._intent_discovered

    def get_intent(self):
        """Повертає намір. Якщо він є. Якщо ні — None. І це ок."""
        if not self._intent_discovered:
            return None
        # Це не рядок.
        # Це вербалізація внутрішнього стану.
        return "hello"
