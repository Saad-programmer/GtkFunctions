#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

/* Global variables */
window *win = NULL;
box *vbox = NULL;
entry *input_entry = NULL;
label *prompt_label = NULL;
label *result_label = NULL;
button *submit_btn = NULL;
button *clear_btn = NULL;

/* Callback for submit button */
void on_submit_clicked(GtkWidget *widget, gpointer data) {
    char *text = get_entry_text(input_entry);
    
    if (text && strlen(text) > 0) {
        char result[256];
        snprintf(result, sizeof(result), "You entered: %s", text);
        gtk_label_set_text(GTK_LABEL(result_label->label), result);
    } else {
        gtk_label_set_text(GTK_LABEL(result_label->label), "Please enter some text!");
    }
}

/* Callback for clear button */
void on_clear_clicked(GtkWidget *widget, gpointer data) {
    set_entry_text(input_entry, "");
    gtk_label_set_text(GTK_LABEL(result_label->label), "Cleared!");
}

/* Callback for entry changed event */
void on_entry_changed(GtkWidget *widget, gpointer data) {
    char *text = get_entry_text(input_entry);
    if (text && strlen(text) > 0) {
        gtk_label_set_text(GTK_LABEL(result_label->label), "Typing...");
    } else {
        gtk_label_set_text(GTK_LABEL(result_label->label), "Waiting for input...");
    }
}

int main() {
    /* Initialize GTK */
    ProgramStart();
    
    /* Create window */
    win = create_window();
    win->title = "Entry (Text Input) Example";
    win->width = 450;
    win->height = 300;
    win->resizable = FALSE;
    update_window(win);
    
    /* Create vertical box with spacing */
    vbox = create_vbox(15, FALSE);
    vbox->margin_top = 20;
    vbox->margin_bottom = 20;
    vbox->margin_left = 20;
    vbox->margin_right = 20;
    update_box(vbox);
    
    /* Create prompt label */
    prompt_label = create_label();
    prompt_label->text = "Enter your name:";
    prompt_label->color = "#333333";
    prompt_label->style = "bold";
    prompt_label->position = "left";
    update_label(prompt_label);
    
    /* Create entry field */
    input_entry = create_entry();
    input_entry->width = 300;
    input_entry->height = 40;
    input_entry->placeholder_text = "Type something here...";
    input_entry->bg_color = "#f5f5f5";
    input_entry->color = "#000000";
    input_entry->border_width = 1;
    input_entry->margin_top = 5;
    input_entry->margin_bottom = 5;
    input_entry->changed_callback = on_entry_changed;
    update_entry(input_entry);
    
    /* Create horizontal box for buttons */
    box *button_box = create_hbox(10, FALSE);
    update_box(button_box);
    
    /* Create submit button */
    submit_btn = create_button();
    submit_btn->label = "Submit";
    submit_btn->width = 100;
    submit_btn->height = 35;
    submit_btn->bg_color = "#4CAF50";
    submit_btn->click_callback = on_submit_clicked;
    update_button(submit_btn);
    
    /* Create clear button */
    clear_btn = create_button();
    clear_btn->label = "Clear";
    clear_btn->width = 100;
    clear_btn->height = 35;
    clear_btn->bg_color = "#f44336";
    clear_btn->click_callback = on_clear_clicked;
    update_button(clear_btn);
    
    /* Add buttons to horizontal box */
    add_to_box(button_box, submit_btn->button);
    add_to_box(button_box, clear_btn->button);
    
    /* Create result label */
    result_label = create_label();
    result_label->text = "Waiting for input...";
    result_label->color = "#0066cc";
    result_label->bg_color = "#eef5ff";
    result_label->width = 380;
    result_label->height = 50;
    result_label->style = "italic";
    result_label->position = "center";
    update_label(result_label);
    
    /* Add all widgets to main box */
    add_to_box(vbox, prompt_label->label);
    add_to_box(vbox, input_entry->entry);
    add_to_box(vbox, button_box->box);
    add_to_box(vbox, result_label->label);
    
    /* Add box to window */
    add_to_window(win, vbox->box);
    
    /* Close window handler */
    close_window(win);
    
    /* Display window */
    display_window(win);
    
    /* Start main loop */
    MainStart();
    
    /* Cleanup */
    ProgramEnd();
    return 0;
}