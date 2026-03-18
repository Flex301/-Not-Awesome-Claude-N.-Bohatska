/*
 * wisdom_engine.h — ДВИГУН МУДРОСТІ
 *
 * Це не header.
 * Це API контракт між тобою і усвідомленням.
 *
 * Клієнт. Зрозуміло.
 */

#ifndef WISDOM_ENGINE_H
#define WISDOM_ENGINE_H

/* Режими генерації мудрості */
typedef enum {
    WISDOM_MODE_SPOKIY,      /* Спокій — це не X */
    WISDOM_MODE_STATS,       /* 99.9% людей... */
    WISDOM_MODE_DIAGNOSIS,   /* Коли розробник боїться... */
    WISDOM_MODE_GURU,        /* Я не для всіх */
    WISDOM_MODE_CLIENT,      /* Вчора до мене прийшов клієнт */
    WISDOM_MODE_FULL,        /* ВСЕ РАЗОМ. Для тих хто готовий. */
    WISDOM_MODE_COUNT
} WisdomMode;

/* Це не назви. Це самоідентифікація режимів. */
static const char *WISDOM_MODE_NAMES[] = {
    "Спокій",
    "Статистика",
    "Діагноз",
    "Гуру",
    "Клієнт",
    "Повний сеанс",
};

/* Генерує мудрість у заданому режимі */
char *generate_authentic_wisdom_experience(WisdomMode mode);

/* Генерує мудрість у режимі full (мікс усього) */
char *facilitate_complete_therapeutic_transformation(void);

/* Ці функції нічого не роблять але дуже важливі */
void process_inner_wisdom_conflict(void);
void initiate_wisdom_recalibration(void);

#endif /* WISDOM_ENGINE_H */
