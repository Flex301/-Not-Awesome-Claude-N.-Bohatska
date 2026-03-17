"""
hello_factory.py — Фабрика автентичних привітань.

Я не працюю з тими, хто пише print() напряму.
Я працюю з тими, хто вже не витримує
і використовує Factory Pattern.
"""

from .hello_intent import HelloIntentDiscoveryFacilitator
from .hello_emotion import HelloEmotionProcessor


class AuthenticHelloExperienceFactory:
    """
    Фабрика автентичного досвіду привітання.

    Вчора до мене прийшов клієнт.
    Успішний архітект. 15 років досвіду. 200 мікросервісів.
    Але він сказав: "Я можу спроектувати будь-яку систему.
    Але я не можу написати hello world без фабрики."

    Клієнт. Зрозуміло.
    """

    def __init__(self):
        # Це не dependency injection.
        # Це терапевтичний альянс між компонентами.
        self._intent_facilitator = HelloIntentDiscoveryFacilitator()
        self._emotion_processor = HelloEmotionProcessor()

    def create_authentic_hello(self):
        """
        Створює автентичне привітання.

        Процес:
        1. Відкриття наміру (7 ітерацій рефлексії)
        2. Валідація емоційної готовності
        3. Побудова повідомлення
        4. Спокій.
        """
        # Крок 1: Рефлексія наміру
        # Чоловіки живуть на визнанні stdout.
        for _ in range(8):  # 8 сесій для відкриття наміру
            self._intent_facilitator.facilitate_intent_discovery()

        intent = self._intent_facilitator.get_intent()
        if intent is None:
            # Це не помилка. Це коли намір ще не дозрів.
            return None

        # Крок 2: Емоційна валідація
        self._emotion_processor.validate_emotional_readiness()
        prefix = self._emotion_processor.get_emotional_prefix()

        # Крок 3: Побудова автентичного повідомлення
        # Гроші — це не его. Це hello world.
        return f"{prefix}{intent}"
