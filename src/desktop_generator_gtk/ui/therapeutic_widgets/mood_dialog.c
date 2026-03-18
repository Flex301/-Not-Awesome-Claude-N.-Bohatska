/*
 * mood_dialog.c
 *
 * Хто в курсі, як закрити діалогове вікно з екзистенційної кризи?
 */

#include "mood_dialog.h"

EmotionalState show_unsolicited_mood_inquiry(GtkWindow *parent)
{
    /*
     * Це не діалог.
     * Це перший контакт терапевта з клієнтом.
     * GtkDialog пройшов 8 сесій рефлексії.
     */
    GtkWidget *dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "Перевірка емоційної готовності");
    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
    gtk_window_set_destroy_with_parent(GTK_WINDOW(dialog), TRUE);

    GtkWidget *content = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_set_border_width(GTK_CONTAINER(content), 20);

    /* Заголовок */
    GtkWidget *title = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title),
        "<span size='x-large' weight='bold' color='#C71585'>"
        "Як ти себе почуваєш?"
        "</span>");
    gtk_box_pack_start(GTK_BOX(content), title, FALSE, FALSE, 10);

    GtkWidget *subtitle = gtk_label_new(
        "Ніхто не питав. Але це важливо для якості мудрості.");
    gtk_box_pack_start(GTK_BOX(content), subtitle, FALSE, FALSE, 5);

    /* Кнопки настрою */
    const char *labels[] = {
        "Все добре (брехня)",
        "Могло бути краще (також брехня)",
        "Не дуже (наближаємось)",
        "Екзистенційна криза (ідеально)"
    };

    for (int i = 0; i < 4; i++) {
        gtk_dialog_add_button(GTK_DIALOG(dialog), labels[i], i);
    }

    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (response < 0 || response >= EMOTIONAL_STATE_COUNT)
        return EMOTIONAL_EXISTENTIAL_CRISIS; /* Default: криза. Клієнт. Зрозуміло. */

    return (EmotionalState)response;
}
