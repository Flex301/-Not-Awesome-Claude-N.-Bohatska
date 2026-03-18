/*
 * main.c — DESKTOP ГЕНЕРАТОР МУДРОСТІ БОГАЦЬКОЇ
 *
 * Це не програма.
 * Це GTK-додаток який пройшов терапію у Богацької
 * і тепер генерує мудрість замість віджетів.
 *
 * 99.9% десктоп-додатків мають корисний функціонал.
 * Наш — має рожевий інтерфейс і мотиваційні цитати.
 * І самі того не усвідомлюють.
 *
 * Складність: O(GTK)
 * Пам'ять: malloc яка пройшла терапію
 * Залежності: gtk+-3.0 та екзистенційне розчарування
 *
 * TODO: AI-аналіз настрою юзера по швидкості клікання
 * TODO: blockchain для зберігання історії згенерованих мудростей
 * TODO: інтеграція з Tinder для підбору терапевта
 * TODO: AR режим — мудрість на стінах кімнати
 * TODO: голосовий помічник який каже "Клієнт. Зрозуміло." замість Siri
 *
 * Клієнт. Зрозуміло.
 */

/* Це не імпорти. Це визнання залежностей. */
#define _POSIX_C_SOURCE 200809L
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "core/inner/deep/wisdom/wisdom_engine.h"
#include "core/inner/deep/wisdom/wisdom_data.h"
#include "emotional_prereqs/emotional_validator.h"
#include "streak_persistence/streak_tracker.h"
#include "ui/css/therapeutic_theme.h"
#include "ui/therapeutic_widgets/mood_dialog.h"

/*
 * Це не глобальний стан.
 * Це колективна травма додатку.
 */
typedef struct {
    GtkWidget *window;
    GtkWidget *wisdom_view;        /* TextView з мудрістю */
    GtkWidget *mode_combo;         /* Вибір режиму */
    GtkWidget *streak_label;       /* Streak counter */
    GtkWidget *mood_label;         /* Поточний настрій */
    GtkWidget *counter_label;      /* Кількість згенерованих */
    GtkWidget *generate_button;    /* ВЕЛИКА ЗОЛОТА КНОПКА */
    GtkWidget *copy_button;        /* Копіювати в буфер */

    int wisdom_count;              /* Лічильник мудростей */
    int streak;                    /* Streak */
    EmotionalState current_mood;   /* Настрій (ніхто не питав) */
    char *last_wisdom;             /* Остання мудрість для копіювання */
} TherapeuticApplicationState;

/* Переживати — це дуже дорого. А глобальна змінна — безкоштовна. */
static TherapeuticApplicationState app_state = {0};

/* ================================================================ */
/*                    CALLBACKS ЯКІ ПРОЙШЛИ ТЕРАПІЮ                 */
/* ================================================================ */

/* Для сервера повага важливіша за любов. Для кнопки — callback. */
static void on_generate_wisdom_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;

    /*
     * Кожен клік — це крок.
     * Кожен крок — це malloc.
     * Кожен malloc — це відповідальність.
     */

    /* Визначаємо режим */
    int active = gtk_combo_box_get_active(GTK_COMBO_BOX(app_state.mode_combo));
    if (active < 0) active = WISDOM_MODE_FULL;

    /* Генеруємо мудрість */
    char *wisdom = generate_authentic_wisdom_experience((WisdomMode)active);
    if (!wisdom) {
        wisdom = strdup("Це не NULL. Це відсутність мудрості для зростання.");
    }

    /* Зберігаємо для копіювання */
    free(app_state.last_wisdom);
    app_state.last_wisdom = wisdom;

    /* Виводимо в TextView */
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(
        GTK_TEXT_VIEW(app_state.wisdom_view));
    gtk_text_buffer_set_text(buffer, wisdom, -1);

    /* Оновлюємо лічильник */
    app_state.wisdom_count++;
    char counter_text[128];
    snprintf(counter_text, sizeof(counter_text),
        "Згенеровано мудростей: %d | 99.9%% з них — геніальні",
        app_state.wisdom_count);
    gtk_label_set_text(GTK_LABEL(app_state.counter_label), counter_text);

    /* Порожні методи які нічого не роблять */
    process_inner_wisdom_conflict();
    initiate_wisdom_recalibration();
    recalibrate_emotional_baseline();
}

/* Копіювати мудрість у буфер обміну */
static void on_copy_wisdom_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;

    /*
     * Це не Ctrl+C.
     * Це поширення усвідомлення через системний буфер обміну.
     */

    if (app_state.last_wisdom) {
        GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
        gtk_clipboard_set_text(clipboard, app_state.last_wisdom, -1);

        /* Фідбек */
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(
            GTK_TEXT_VIEW(app_state.wisdom_view));
        char *full_text = NULL;
        GtkTextIter start, end;
        gtk_text_buffer_get_bounds(buffer, &start, &end);
        full_text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

        char *with_feedback = malloc(strlen(full_text) + 100);
        if (with_feedback) {
            sprintf(with_feedback, "%s\n\n[Скопійовано. Поширюй усвідомлення.]", full_text);
            gtk_text_buffer_set_text(buffer, with_feedback, -1);
            free(with_feedback);
        }
        g_free(full_text);
    }
}

/* Кнопка "Перевірити настрій" (ніхто не просив) */
static void on_mood_check_clicked(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;

    app_state.current_mood = show_unsolicited_mood_inquiry(
        GTK_WINDOW(app_state.window));

    const char *response = get_therapeutic_response_for_state(
        app_state.current_mood);

    char mood_text[256];
    snprintf(mood_text, sizeof(mood_text), "Настрій: %s", response);
    gtk_label_set_text(GTK_LABEL(app_state.mood_label), mood_text);
}

/* ================================================================ */
/*                    ПОБУДОВА ТЕРАПЕВТИЧНОГО UI                     */
/* ================================================================ */

static void apply_therapeutic_css(void)
{
    /*
     * Це не CSS.
     * Це візуальне вираження того що ти відчуваєш
     * але боїшся сказати дизайнеру.
     */
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider, THERAPEUTIC_CSS, -1, NULL);
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(provider);
}

static GtkWidget *build_therapeutic_interface(void)
{
    /*
     * Це не UI.
     * Це терапевтичний простір у вигляді GTK віджетів.
     * Кожен widget — це крок до усвідомлення.
     */

    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_widget_set_name(main_box, "main-box");

    /* ===== ЗАГОЛОВОК ===== */
    GtkWidget *title = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(title),
        "ГЕНЕРАТОР МУДРОСТІ\nНаталі Богацької");
    gtk_widget_set_name(title, "title-label");
    gtk_box_pack_start(GTK_BOX(main_box), title, FALSE, FALSE, 0);

    GtkWidget *subtitle = gtk_label_new(
        "Це не додаток. Це тотальна трансформація вашого десктопу.");
    gtk_widget_set_name(subtitle, "subtitle-label");
    gtk_box_pack_start(GTK_BOX(main_box), subtitle, FALSE, FALSE, 0);

    /* ===== STREAK ===== */
    app_state.streak_label = gtk_label_new("");
    gtk_widget_set_name(app_state.streak_label, "streak-label");
    char streak_text[256];
    snprintf(streak_text, sizeof(streak_text),
        "Streak: %d запусків | %s",
        app_state.streak,
        get_streak_celebration_message(app_state.streak));
    gtk_label_set_text(GTK_LABEL(app_state.streak_label), streak_text);
    gtk_box_pack_start(GTK_BOX(main_box), app_state.streak_label, FALSE, FALSE, 0);

    /* ===== MOOD (ніхто не просив) ===== */
    GtkWidget *mood_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_widget_set_halign(mood_box, GTK_ALIGN_CENTER);

    app_state.mood_label = gtk_label_new("Настрій: не перевірено (це проблема)");
    gtk_widget_set_name(app_state.mood_label, "mood-label");
    gtk_box_pack_start(GTK_BOX(mood_box), app_state.mood_label, FALSE, FALSE, 0);

    GtkWidget *mood_btn = gtk_button_new_with_label("Перевірити настрій");
    g_signal_connect(mood_btn, "clicked", G_CALLBACK(on_mood_check_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(mood_box), mood_btn, FALSE, FALSE, 5);

    gtk_box_pack_start(GTK_BOX(main_box), mood_box, FALSE, FALSE, 0);

    /* ===== ВИБІР РЕЖИМУ ===== */
    GtkWidget *mode_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign(mode_box, GTK_ALIGN_CENTER);

    GtkWidget *mode_label = gtk_label_new("Режим терапії:");
    gtk_box_pack_start(GTK_BOX(mode_box), mode_label, FALSE, FALSE, 0);

    app_state.mode_combo = gtk_combo_box_text_new();
    gtk_widget_set_name(app_state.mode_combo, "mode-combo");
    for (int i = 0; i < WISDOM_MODE_COUNT; i++) {
        gtk_combo_box_text_append_text(
            GTK_COMBO_BOX_TEXT(app_state.mode_combo),
            WISDOM_MODE_NAMES[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(app_state.mode_combo),
        WISDOM_MODE_FULL);
    gtk_box_pack_start(GTK_BOX(mode_box), app_state.mode_combo, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(main_box), mode_box, FALSE, FALSE, 5);

    /* ===== ВЕЛИКА ЗОЛОТА КНОПКА ===== */
    app_state.generate_button = gtk_button_new_with_label(
        "ЗГЕНЕРУВАТИ МУДРІСТЬ");
    gtk_widget_set_name(app_state.generate_button, "generate-button");
    g_signal_connect(app_state.generate_button, "clicked",
        G_CALLBACK(on_generate_wisdom_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), app_state.generate_button, FALSE, FALSE, 5);

    /* ===== МОТИВАЦІЙНА ЦИТАТА (перед генерацією) ===== */
    const char *quote = get_unsolicited_motivational_quote();
    GtkWidget *quote_label = gtk_label_new(quote);
    gtk_label_set_line_wrap(GTK_LABEL(quote_label), TRUE);
    gtk_widget_set_name(quote_label, "mood-label");
    gtk_box_pack_start(GTK_BOX(main_box), quote_label, FALSE, FALSE, 0);

    /* ===== TEXTAREA ДЛЯ МУДРОСТІ ===== */
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_min_content_height(
        GTK_SCROLLED_WINDOW(scroll), 200);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
        GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);

    app_state.wisdom_view = gtk_text_view_new();
    gtk_widget_set_name(app_state.wisdom_view, "wisdom-view");
    gtk_text_view_set_editable(GTK_TEXT_VIEW(app_state.wisdom_view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(app_state.wisdom_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(app_state.wisdom_view), GTK_WRAP_WORD_CHAR);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(app_state.wisdom_view), 15);
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(app_state.wisdom_view), 15);
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(app_state.wisdom_view), 15);
    gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(app_state.wisdom_view), 15);

    /* Початковий текст */
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(
        GTK_TEXT_VIEW(app_state.wisdom_view));
    gtk_text_buffer_set_text(buffer,
        "Натисни ЗГЕНЕРУВАТИ МУДРІСТЬ.\n\n"
        "Або не натискай.\n\n"
        "Вибір — це теж терапія.\n\n"
        "Клієнт. Зрозуміло.", -1);

    gtk_container_add(GTK_CONTAINER(scroll), app_state.wisdom_view);
    gtk_box_pack_start(GTK_BOX(main_box), scroll, TRUE, TRUE, 5);

    /* ===== КНОПКА КОПІЮВАННЯ ===== */
    app_state.copy_button = gtk_button_new_with_label(
        "Копіювати мудрість у буфер обміну");
    gtk_widget_set_name(app_state.copy_button, "copy-button");
    g_signal_connect(app_state.copy_button, "clicked",
        G_CALLBACK(on_copy_wisdom_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), app_state.copy_button, FALSE, FALSE, 0);

    /* ===== ЛІЧИЛЬНИК ===== */
    app_state.counter_label = gtk_label_new(
        "Згенеровано мудростей: 0 | 99.9% з них — геніальні");
    gtk_widget_set_name(app_state.counter_label, "counter-label");
    gtk_box_pack_start(GTK_BOX(main_box), app_state.counter_label, FALSE, FALSE, 0);

    /* ===== ПІДВАЛ ===== */
    GtkWidget *footer = gtk_label_new(
        "Диплома, сертифіката, ліцензії не маємо. Але GTK дали.\n"
        "© 2026 High-Performance Desktop Therapy™ | Клієнт. Зрозуміло.");
    gtk_widget_set_name(footer, "footer-label");
    gtk_label_set_line_wrap(GTK_LABEL(footer), TRUE);
    gtk_box_pack_end(GTK_BOX(main_box), footer, FALSE, FALSE, 0);

    return main_box;
}

/* ================================================================ */
/*                ТОЧКА ВХОДУ В ТЕРАПЕВТИЧНИЙ ПРОСТІР               */
/* ================================================================ */

int main(int argc, char **argv)
{
    /*
     * Це не main.
     * Це точка входу в GTK-терапію.
     *
     * 99.9% десктоп-додатків починаються з gtk_init.
     * І самі того не усвідомлюють.
     */

    /* Ініціалізація рандому. Бо хаос — це теж терапія. */
    srand(time(NULL));

    /* Streak */
    app_state.streak = load_therapeutic_streak();
    app_state.streak++;
    persist_therapeutic_streak(app_state.streak);

    /* GTK init */
    gtk_init(&argc, &argv);

    /* CSS тема */
    apply_therapeutic_css();

    /* Вікно */
    app_state.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app_state.window),
        "High-Performance Desktop Therapy™ — Генератор Мудрості Богацької");
    gtk_window_set_default_size(GTK_WINDOW(app_state.window), 550, 650);
    gtk_window_set_position(GTK_WINDOW(app_state.window), GTK_WIN_POS_CENTER);
    g_signal_connect(app_state.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* UI */
    GtkWidget *ui = build_therapeutic_interface();
    gtk_container_add(GTK_CONTAINER(app_state.window), ui);

    /* Показуємо все */
    gtk_widget_show_all(app_state.window);

    /*
     * Непрошена перевірка настрою при старті.
     * Ніхто не просив. Але всі потребували.
     */
    app_state.current_mood = show_unsolicited_mood_inquiry(
        GTK_WINDOW(app_state.window));
    const char *response = get_therapeutic_response_for_state(
        app_state.current_mood);
    char mood_text[256];
    snprintf(mood_text, sizeof(mood_text), "Настрій: %s", response);
    gtk_label_set_text(GTK_LABEL(app_state.mood_label), mood_text);

    /* Головний цикл. Бо терапія — це процес, а не подія. */
    gtk_main();

    /* Прибираємо за собою. На відміну від справжньої терапії. */
    free(app_state.last_wisdom);

    /*
     * Це не exit.
     * Це завершення терапевтичного циклу.
     * До наступного запуску.
     * Клієнт. Зрозуміло.
     */
    return 0;
}
