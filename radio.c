#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

window *win = NULL;
box *vbox = NULL;
box *styled_box = NULL;
radio_button *small = NULL;
radio_button *medium = NULL;
radio_button *large = NULL;
label *price_label = NULL;

void on_size_changed(GtkWidget *widget, gpointer data) {
    char price[100];
    
    if (is_radio_button_active(small))
        snprintf(price, sizeof(price), "Price: $5.99");
    else if (is_radio_button_active(medium))
        snprintf(price, sizeof(price), "Price: $7.99");
    else if (is_radio_button_active(large))
        snprintf(price, sizeof(price), "Price: $9.99");
    
    gtk_label_set_text(GTK_LABEL(price_label->label), price);
}

int main() {
    ProgramStart();
    
    win = create_window();
    win->title = "Coffee Size Selector";
    win->width = 350;
    win->height = 280;
    win->bg_color = "#f5f0e1";
    update_window(win);
    
    /* Main box */
    vbox = create_vbox(15, FALSE);
    vbox->bg_color = "#f5f0e1";
    update_box(vbox);
    
    /* Title */
    label *title = create_label();
    title->text = "Select Coffee Size";
    title->color = "#6b3e1f";
    title->style = "bold";
    title->font_family = "Georgia";
    title->position = "center";
    update_label(title);
    
    /* Styled box for radio buttons */
    styled_box = create_vbox(8, FALSE);
    styled_box->bg_color = "#fff8f0";
    styled_box->border_width = 2;
    update_box(styled_box);
    
    /* Radio buttons */
    small = create_radio_button("size_group", "Small (8 oz)");
    small->color = "#333";
    small->active = TRUE;
    small->toggled_callback = on_size_changed;
    update_radio_button(small);
    
    medium = create_radio_button("size_group", "Medium (12 oz)");
    medium->color = "#333";
    medium->toggled_callback = on_size_changed;
    update_radio_button(medium);
    
    large = create_radio_button("size_group", "Large (16 oz)");
    large->color = "#333";
    large->toggled_callback = on_size_changed;
    update_radio_button(large);
    
    /* Price label */
    price_label = create_label();
    price_label->text = "Price: $5.99";
    price_label->color = "#d2691e";
    price_label->style = "bold";
    price_label->font_family = "Arial";
    price_label->position = "center";
    price_label->bg_color = "#fff8f0";
    price_label->width = 200;
    price_label->height = 40;
    update_label(price_label);
    
    /* Add to styled box */
    add_to_box(styled_box, small->radio_button);
    add_to_box(styled_box, medium->radio_button);
    add_to_box(styled_box, large->radio_button);
    
    /* Add all to main box */
    add_to_box(vbox, title->label);
    add_to_box(vbox, styled_box->box);
    add_to_box(vbox, price_label->label);
    
    add_to_window(win, vbox->box);
    close_window(win);
    display_window(win);
    
    MainStart();
    ProgramEnd();
    return 0;
}