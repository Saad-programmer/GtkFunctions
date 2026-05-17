#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

window *win = NULL;
box *main_vbox = NULL;
box *name_hbox = NULL;
box *email_hbox = NULL;
box *button_hbox = NULL;

label *name_label = NULL;
entry *name_entry = NULL;
label *email_label = NULL;
entry *email_entry = NULL;
button *submit_btn = NULL;
button *clear_btn = NULL;
label *result_label = NULL;

void on_submit_clicked(GtkWidget *widget, gpointer data) {
    char *name = get_entry_text(name_entry);
    char *email = get_entry_text(email_entry);
    char result[256];
    
    if (strlen(name) > 0 && strlen(email) > 0) {
        snprintf(result, sizeof(result), "Hello %s! (%s)", name, email);
        gtk_label_set_text(GTK_LABEL(result_label->label), result);
    } else {
        gtk_label_set_text(GTK_LABEL(result_label->label), "Please fill all fields");
    }
}

void on_clear_clicked(GtkWidget *widget, gpointer data) {
    set_entry_text(name_entry, "");
    set_entry_text(email_entry, "");
    gtk_label_set_text(GTK_LABEL(result_label->label), "Cleared!");
}

int main() {
    ProgramStart();
    
    /* Create window */
    win = create_window();
    win->title = "VBox + HBox Layout Example";
    win->width = 450;
    win->height = 350;
    update_window(win);
    
    /* Main vertical box (everything goes in here) */
    main_vbox = create_vbox(15, FALSE);
    main_vbox->margin_top = 20;
    main_vbox->margin_bottom = 20;
    main_vbox->margin_left = 20;
    main_vbox->margin_right = 20;
    update_box(main_vbox);
    
    /* === Row 1: Name (Label + Entry in HBox) === */
    name_hbox = create_hbox(10, FALSE);
    update_box(name_hbox);
    
    name_label = create_label();
    name_label->text = "Name:";
    name_label->width = 80;
    name_label->style = "bold";
    update_label(name_label);
    
    name_entry = create_entry();
    name_entry->width = 250;
    name_entry->placeholder_text = "Enter your name";
    update_entry(name_entry);
    
    add_to_box(name_hbox, name_label->label);
    add_to_box(name_hbox, name_entry->entry);
    
    /* === Row 2: Email (Label + Entry in HBox) === */
    email_hbox = create_hbox(10, FALSE);
    update_box(email_hbox);
    
    email_label = create_label();
    email_label->text = "Email:";
    email_label->width = 80;
    email_label->style = "bold";
    update_label(email_label);
    
    email_entry = create_entry();
    email_entry->width = 250;
    email_entry->placeholder_text = "Enter your email";
    update_entry(email_entry);
    
    add_to_box(email_hbox, email_label->label);
    add_to_box(email_hbox, email_entry->entry);
    
    /* === Row 3: Buttons (Submit + Clear in HBox) === */
    button_hbox = create_hbox(10, TRUE);  /* TRUE = equal width buttons */
    update_box(button_hbox);
    
    submit_btn = create_button();
    submit_btn->label = "Submit";
    submit_btn->bg_color = "#4CAF50";
    submit_btn->click_callback = on_submit_clicked;
    update_button(submit_btn);
    
    clear_btn = create_button();
    clear_btn->label = "Clear";
    clear_btn->bg_color = "#f44336";
    clear_btn->click_callback = on_clear_clicked;
    update_button(clear_btn);
    
    add_to_box(button_hbox, submit_btn->button);
    add_to_box(button_hbox, clear_btn->button);
    
    /* === Result label (full width) === */
    result_label = create_label();
    result_label->text = "Fill the form and click Submit";
    result_label->color = "#0066cc";
    result_label->bg_color = "#eef5ff";
    result_label->width = 380;
    result_label->height = 50;
    result_label->position = "center";
    update_label(result_label);
    
    /* Add all rows to main vertical box */
    add_to_box(main_vbox, name_hbox->box);
    add_to_box(main_vbox, email_hbox->box);
    add_to_box(main_vbox, button_hbox->box);
    add_to_box(main_vbox, result_label->label);
    
    /* Add main box to window */
    add_to_window(win, main_vbox->box);
    
    close_window(win);
    display_window(win);
    
    MainStart();
    ProgramEnd();
    return 0;
}