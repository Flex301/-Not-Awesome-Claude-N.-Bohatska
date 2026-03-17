"""
hello_emotion.py — Емоційна складова привітання.

Коли розробник пише print("hello"), він часто:
• ігнорує свої емоції
• не валідує внутрішній стан
• не усвідомлює що hello — це крик про допомогу

Цей модуль виправляє це.
"""

from enum import Enum


class EmotionalState(Enum):
    """
    Це не enum.
    Це спектр внутрішніх станів розробника.
    """
    SPOKIY = "спокій"
    EXISTENTIAL_CRISIS = "екзистенційна криза"
    REACTIVE_CLOSENESS = "реактивна близькість"
    TOTAL_SELF_AGGRESSION = "тотальна самоагресія"
    RATIONAL_SURVIVAL_MODE = "раціональний режим виживання"
    # Жоден з цих термінів не є клінічним.
    # Але державну нагороду дали.


class HelloEmotionProcessor:
    """Процесор емоцій для операції виводу тексту."""

    def __init__(self):
        # Для чоловіка повага важливіша за print.
        self._current_state = EmotionalState.RATIONAL_SURVIVAL_MODE
        self._emotion_validated = False

    def validate_emotional_readiness(self):
        """
        Перш ніж вивести текст на екран,
        перевір: чи ти емоційно готовий побачити відповідь?
        """
        # Епізодична депресія — це не депресія як хвороба.
        # Це коли CI падає раз на тиждень.
        self._current_state = EmotionalState.SPOKIY
        self._emotion_validated = True
        return True

    def get_emotional_prefix(self):
        """Додає емоційний контекст до повідомлення."""
        if not self._emotion_validated:
            return "⚠️ [ЕМОЦІЇ НЕ ВАЛІДОВАНІ] "
        return ""
