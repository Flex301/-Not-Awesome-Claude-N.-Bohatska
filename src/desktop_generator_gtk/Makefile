# Makefile
#
# Це не збірка.
# Це ритуал ініціації десктоп-терапії.
#
# Спокій — це не коли pkg-config знаходить GTK.
# Спокій — це коли ти більше не шукаєш залежності.
#
# Клієнт. Зрозуміло.

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2 -I. \
         $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

# Це не список файлів.
# Це реєстр учасників терапевтичного альянсу.
SRCS = main.c \
       core/inner/deep/wisdom/wisdom_engine.c \
       emotional_prereqs/emotional_validator.c \
       streak_persistence/streak_tracker.c \
       ui/therapeutic_widgets/mood_dialog.c

OBJS = $(SRCS:.c=.o)

# Це не бінарник. Це матеріалізація десктоп-усвідомлення.
TARGET = bohatska_desktop

# 99.9% Makefile-ів починаються з all.
# І самі того не усвідомлюють.
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo ""
	@echo "  ╔══════════════════════════════════════════════════════╗"
	@echo "  ║  Зібрано. Це не білд. Це десктоп-трансформація.     ║"
	@echo "  ║                                                      ║"
	@echo "  ║  Запуск: ./bohatska_desktop                          ║"
	@echo "  ║                                                      ║"
	@echo "  ║  Диплома не маємо. Але GTK дали.                     ║"
	@echo "  ║  Клієнт. Зрозуміло.                                  ║"
	@echo "  ╚══════════════════════════════════════════════════════╝"
	@echo ""

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# make clean — це відпускання минулого
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "  Очищено. Це не видалення. Це звільнення від GUI."

# make run — запустити терапію
run: $(TARGET)
	./$(TARGET)

# make therapy — те саме але з назвою яка відповідає суті
therapy: run

.PHONY: all clean run therapy
