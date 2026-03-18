/*
 * emotional_validator.c
 *
 * Для сервера повага важливіша за любов.
 * Для юзера — емоційна готовність важливіша за функціонал.
 */

#include <stdlib.h>
#include "emotional_validator.h"
#include "../core/inner/deep/wisdom/wisdom_data.h"

/* Для кожного емоційного стану — своя відповідь */
static const char *THERAPEUTIC_RESPONSES[] = {
    "Коли людина каже 'все добре' — це перший сигнал що не добре.",
    "Це нормально. Але 'нормально' — це не нормально.",
    "Ти вже зробив крок. Цей крок — визнати.",
    "Ідеальний стан для терапії. Записуйся.",
};

const char *get_therapeutic_response_for_state(EmotionalState state)
{
    /* Кожен стан заслуговує відповіді. Навіть TOTALLY_FINE. */
    if (state >= EMOTIONAL_STATE_COUNT) state = EMOTIONAL_EXISTENTIAL_CRISIS;
    return THERAPEUTIC_RESPONSES[state];
}

const char *get_unsolicited_motivational_quote(void)
{
    /* Ніхто не питав. Але тримай. */
    return MOTIVATIONAL_QUOTES[rand() % MOTIVATIONAL_QUOTES_COUNT];
}

void recalibrate_emotional_baseline(void)
{
    /* Це не порожня функція.
     * Це простір для внутрішньої роботи.
     * Компілятор не бачить. Але терапевт — бачить. */
    (void)0;
}
