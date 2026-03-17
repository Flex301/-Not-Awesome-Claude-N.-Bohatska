"""
hello_output.py — Фінальний вивід привітання.

Після 4 модулів, 3 класів та 8 сесій рефлексії —
ми нарешті готові вивести "hello" на екран.

Це не print.
Це кульмінація внутрішнього шляху.
"""

from .hello_factory import AuthenticHelloExperienceFactory


class MindfulOutputChannel:
    """
    Усвідомлений канал виводу.

    Звичайний print() — це як чоловік який працює 24/7
    і думає що все ок. Але всередині — ні.

    MindfulOutputChannel — це print() який пройшов терапію.
    """

    def __init__(self):
        self._output_count = 0
        self._factory = AuthenticHelloExperienceFactory()

    def emit(self):
        """
        Виводить повідомлення.

        Це не метод. Це останній крок.
        Після цього — спокій.
        """
        message = self._factory.create_authentic_hello()

        if message is None:
            # Іноді найкращий вивід — це тиша.
            # 99.9% розробників не розуміють цього.
            print("...")
            return

        # Нарешті.
        # 4 файли. 3 класи. 8 ітерацій рефлексії.
        # Заради одного print().
        # Клієнт. Зрозуміло.
        print(message)
        self._output_count += 1


def main():
    """
    Точка входу.

    Спокій — це не коли main() працює.
    Спокій — це коли ти більше не боїшся його запустити.
    """
    channel = MindfulOutputChannel()
    channel.emit()


if __name__ == "__main__":
    main()
