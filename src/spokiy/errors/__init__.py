"""
errors — Екзистенційні помилки.

Це не error handling.
Це emotional handling.
"""


class SpokiyBaseError(Exception):
    """
    Базова помилка.

    Спокій — це не коли немає помилок.
    Спокій — це коли помилки більше не лякають.
    """
    pass


class ExistentialAuthenticationCrisisError(SpokiyBaseError):
    """Error 401: Це не unauthorized. Це криза ідентичності."""

    def __str__(self):
        return (
            "Error 401: Це не unauthorized.\n"
            "Це криза ідентичності.\n"
            "Ти не знаєш хто ти. І сервер теж."
        )


class ReactiveClosenessToTimeoutError(SpokiyBaseError):
    """Error 408: Реактивна близькість до timeout."""

    def __str__(self):
        return (
            "Error 408: Це не timeout.\n"
            "Це коли сервер занадто довго тримав з'єднання\n"
            "і не зміг відпустити."
        )


class ExistentialDisappointmentInMicroservicesError(SpokiyBaseError):
    """Error 503: Екзистенційне розчарування у мікросервісній архітектурі."""

    def __str__(self):
        return (
            "Error 503: Це не downtime.\n"
            "Це екзистенційне розчарування\n"
            "у мікросервісній архітектурі.\n\n"
            "Сервіс не впав. Він ліг. Бо втомився тримати.\n"
            "Як чоловік який 20 років тримав бізнес\n"
            "і одного дня зрозумів що не тримає нічого.\n\n"
            "Клієнт. Зрозуміло."
        )


class TotalSelfAggressionInProductionError(SpokiyBaseError):
    """Error 500: Тотальна самоагресія в production."""

    def __str__(self):
        return (
            "Error 500: Тотальна самоагресія.\n"
            "Сервер знищив сам себе.\n"
            "Не тому що хтось атакував.\n"
            "А тому що внутрішній критик сказав:\n"
            "'Ти повинен обробити цей request.'\n"
            "І він не витримав."
        )


class NotReadyForTherapyError(SpokiyBaseError):
    """Error 402: Якщо тобі шкода грошей — тобі не до цього API."""

    def __str__(self):
        return (
            "Error 402: Payment Required.\n"
            "Якщо тобі шкода грошей на цей API —\n"
            "тобі не до нас.\n"
            "Мої ендпоінти не торгуються."
        )


class RegressionIsNotRegressionError(SpokiyBaseError):
    """Це не regression. Це повернення до себе справжнього."""

    def __str__(self):
        return (
            "Це не regression.\n"
            "Це повернення до себе справжнього.\n"
            "Код був кращим раніше?\n"
            "Чи це ти був кращим?\n"
            "Подумай про це."
        )


class MemoryLeakIsNotMemoryLeakError(SpokiyBaseError):
    """Це не memory leak. Це коли програма не може відпустити минуле."""

    def __str__(self):
        return (
            "Це не memory leak.\n"
            "Це коли програма не може відпустити минуле.\n"
            "gc.collect() не допоможе.\n"
            "Тут потрібна терапія.\n"
            "Записуйся."
        )
