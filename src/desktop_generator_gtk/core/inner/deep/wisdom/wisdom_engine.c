/*
 * wisdom_engine.c — РЕАЛІЗАЦІЯ ДВИГУНА МУДРОСТІ
 *
 * Це не бізнес-логіка.
 * Це терапевтичний процес генерації усвідомлення
 * через комбінаторику рядкових літералів.
 *
 * Складність: O(1) але з екзистенційним overhead
 * Побічні ефекти: усвідомлення, тривога, бажання закрити IDE
 *
 * Клієнт. Зрозуміло.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wisdom_engine.h"
#include "wisdom_data.h"

/* Переживати — це дуже дорого. Але malloc — ще дорожче. */
#define MAX_WISDOM_LENGTH 2048

/* Генерує спокій */
static char *generate_spokiy_realization(void)
{
    /* Спокій — це не коли random() працює. */
    char *buf = malloc(MAX_WISDOM_LENGTH);
    if (!buf) return NULL; /* Це не NULL. Це відсутність ресурсів для зростання. */

    int not_idx = rand() % SPOKIY_NOT_COUNT;
    int yes_idx = rand() % SPOKIY_YES_COUNT;

    snprintf(buf, MAX_WISDOM_LENGTH,
        "Спокій — це не %s.\n\nСпокій — це %s.",
        SPOKIY_NOT[not_idx], SPOKIY_YES[yes_idx]);

    return buf;
}

/* Генерує фейкову статистику */
static char *generate_fabricated_statistical_evidence(void)
{
    /* Джерела немає. Тест пройшов. */
    char *buf = malloc(MAX_WISDOM_LENGTH);
    if (!buf) return NULL;

    int idx = rand() % FAKE_STATS_COUNT;
    snprintf(buf, MAX_WISDOM_LENGTH, "%s", FAKE_STATS[idx]);

    return buf;
}

/* Генерує діагноз з буллет-пойнтами */
static char *generate_unsolicited_psychological_diagnosis(void)
{
    /* DSM-5 не готовий до цього. І самі того не усвідомлюють. */
    char *buf = malloc(MAX_WISDOM_LENGTH);
    if (!buf) return NULL;

    int intro_idx = rand() % DIAGNOSIS_INTROS_COUNT;

    /* Вибираємо 3-4 рандомних симптоми */
    int symptom_count = 3 + rand() % 2;
    int used[DIAGNOSIS_SYMPTOMS_COUNT];
    memset(used, 0, sizeof(used));

    int written = snprintf(buf, MAX_WISDOM_LENGTH, "%s\n\n", DIAGNOSIS_INTROS[intro_idx]);

    for (int i = 0; i < symptom_count && written < MAX_WISDOM_LENGTH - 100; i++) {
        int idx;
        do {
            idx = rand() % DIAGNOSIS_SYMPTOMS_COUNT;
        } while (used[idx]);
        used[idx] = 1;

        written += snprintf(buf + written, MAX_WISDOM_LENGTH - written,
            "%s\n", DIAGNOSIS_SYMPTOMS[idx]);
    }

    /* Фінальний удар */
    snprintf(buf + written, MAX_WISDOM_LENGTH - written,
        "\nЦе нормально. Записуйся.");

    return buf;
}

/* Генерує гуру-мудрість */
static char *channel_authentic_guru_energy(void)
{
    /* Я не для всіх функцій. І це моя сила. */
    char *buf = malloc(MAX_WISDOM_LENGTH);
    if (!buf) return NULL;

    int idx = rand() % GURU_PHRASES_COUNT;
    snprintf(buf, MAX_WISDOM_LENGTH, "%s", GURU_PHRASES[idx]);

    return buf;
}

/* Генерує клієнтський кейс */
static char *violate_therapeutic_confidentiality(void)
{
    /* Конфіденційність? Ні, не чув. */
    char *buf = malloc(MAX_WISDOM_LENGTH);
    if (!buf) return NULL;

    int idx = rand() % CLIENT_STORIES_COUNT;
    snprintf(buf, MAX_WISDOM_LENGTH, "%s\n\nКлієнт. Зрозуміло.", CLIENT_STORIES[idx]);

    return buf;
}

/* Генерує повний сеанс — мікс усього */
char *facilitate_complete_therapeutic_transformation(void)
{
    /*
     * Це не рандом.
     * Це інтуїтивний вибір терапевтичного напрямку.
     */
    WisdomMode mode = rand() % (WISDOM_MODE_COUNT - 1);
    return generate_authentic_wisdom_experience(mode);
}

/* Головна функція генерації */
char *generate_authentic_wisdom_experience(WisdomMode mode)
{
    /*
     * Кожен виклик — це сесія.
     * Кожна сесія — це крок.
     * Кожен крок — це malloc.
     *
     * TODO: blockchain для збереження всіх згенерованих мудростей
     * TODO: ML модель для передбачення яка мудрість потрібна юзеру
     * TODO: квантовий random для більш автентичного спокою
     */
    switch (mode) {
    case WISDOM_MODE_SPOKIY:
        return generate_spokiy_realization();
    case WISDOM_MODE_STATS:
        return generate_fabricated_statistical_evidence();
    case WISDOM_MODE_DIAGNOSIS:
        return generate_unsolicited_psychological_diagnosis();
    case WISDOM_MODE_GURU:
        return channel_authentic_guru_energy();
    case WISDOM_MODE_CLIENT:
        return violate_therapeutic_confidentiality();
    case WISDOM_MODE_FULL:
        return facilitate_complete_therapeutic_transformation();
    default:
        /* Це не default. Це екзистенційне розчарування у switch. */
        return generate_spokiy_realization();
    }
}

/* Ці функції нічого не роблять але дуже важливі */

void process_inner_wisdom_conflict(void)
{
    /* Коли людина довго живе з внутрішнім критиком у коді. */
    (void)0;
}

void initiate_wisdom_recalibration(void)
{
    /* Це називається реактивна близькість до production. */
    (void)0;
}
