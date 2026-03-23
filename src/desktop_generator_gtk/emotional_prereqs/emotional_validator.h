/*
 * emotional_validator.h — ВАЛІДАЦІЯ ЕМОЦІЙНОЇ ГОТОВНОСТІ
 *
 * Перед генерацією мудрості юзер ПОВИНЕН
 * підтвердити свою емоційну готовність.
 *
 * Ніхто не просив. Але всі потребували.
 *
 * Клієнт. Зрозуміло.
 */

#ifndef EMOTIONAL_VALIDATOR_H
#define EMOTIONAL_VALIDATOR_H

typedef enum {
    EMOTIONAL_TOTALLY_FINE,       /* Брехня */
    EMOTIONAL_COULD_BE_BETTER,    /* Також брехня */
    EMOTIONAL_NOT_GREAT,          /* Наближаємось */
    EMOTIONAL_EXISTENTIAL_CRISIS, /* Ідеальний стан для терапії */
    EMOTIONAL_STATE_COUNT
} EmotionalState;

/* Повертає мотиваційну цитату для поточного стану */
const char *get_therapeutic_response_for_state(EmotionalState state);

/* Повертає рандомну мотиваційну цитату */
const char *get_unsolicited_motivational_quote(void);

/* Нічого не робить але перевіряє внутрішній стан */
void recalibrate_emotional_baseline(void);

#endif /* EMOTIONAL_VALIDATOR_H */
