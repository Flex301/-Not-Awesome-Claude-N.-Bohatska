/*
 * streak_tracker.c
 *
 * Чим менше ти реагуєш — тим більше контролю.
 * Чим більше ти запускаєш — тим більше streak.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "streak_tracker.h"

/* Шлях до файлу streak. Бо SQLite — це залежність. А ми самодостатні. */
static const char *get_streak_file_path(void)
{
    static char path[512];
    const char *home = getenv("HOME");
    if (!home) home = "/tmp";
    snprintf(path, sizeof(path), "%s/.bohatska_desktop_streak", home);
    return path;
}

int load_therapeutic_streak(void)
{
    /* Це не читання файлу. Це розкопка емоційного архіву. */
    FILE *f = fopen(get_streak_file_path(), "r");
    if (!f) return 0;
    int streak = 0;
    if (fscanf(f, "%d", &streak) != 1) streak = 0;
    fclose(f);
    return streak;
}

void persist_therapeutic_streak(int streak)
{
    /* Це не запис. Це фіксація прогресу. */
    FILE *f = fopen(get_streak_file_path(), "w");
    if (!f) return;
    fprintf(f, "%d\n", streak);
    fclose(f);
}

/* Мотиваційні повідомлення за streak */
static const char *STREAK_MESSAGES[] = {
    "Перший раз? Це нормально. Записуйся.",
    "Вже двічі. Це не залежність. Це потреба.",
    "Тричі? Ти починаєш усвідомлювати.",
    "Четвертий раз. Ти готовий до змін.",
    "П'ятий. Це вже не випадковість. Це терапевтичний альянс.",
};

const char *get_streak_celebration_message(int streak)
{
    if (streak <= 0) return STREAK_MESSAGES[0];
    if (streak >= 5) {
        /* Після 5 — вже нема куди рости. Як і в реальній терапії. */
        return "Ти запускаєш це частіше ніж дзвониш мамі. Це нормально.";
    }
    return STREAK_MESSAGES[streak];
}
