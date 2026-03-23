/*
 * mood_dialog.h — НЕПРОШЕНИЙ ДІАЛОГ ЕМОЦІЙНОЇ ГОТОВНОСТІ
 *
 * Перед тим як згенерувати мудрість
 * треба спитати як ти себе почуваєш.
 *
 * Ніхто не просив.
 * Але всі потребували.
 */

#ifndef MOOD_DIALOG_H
#define MOOD_DIALOG_H

#include <gtk/gtk.h>
#include "../../emotional_prereqs/emotional_validator.h"

/* Показує діалог і повертає вибраний стан */
EmotionalState show_unsolicited_mood_inquiry(GtkWindow *parent);

#endif /* MOOD_DIALOG_H */
