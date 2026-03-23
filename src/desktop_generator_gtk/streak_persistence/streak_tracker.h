/*
 * streak_tracker.h — ЛІЧИЛЬНИК ПОСЛІДОВНИХ ЗАПУСКІВ БЕЗ СЛІЗ
 *
 * Зберігає streak у файлі ~/.bohatska_desktop_streak
 * Бо кожен запуск — це крок.
 *
 * Клієнт. Зрозуміло.
 */

#ifndef STREAK_TRACKER_H
#define STREAK_TRACKER_H

/* Завантажити streak з файлу (0 якщо немає) */
int load_therapeutic_streak(void);

/* Зберегти streak */
void persist_therapeutic_streak(int streak);

/* Повертає мотиваційне повідомлення для streak */
const char *get_streak_celebration_message(int streak);

#endif /* STREAK_TRACKER_H */
