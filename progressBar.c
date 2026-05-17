#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

/* Global variables */
window *win = NULL;
box *vbox = NULL;
progress_bar *pb = NULL;
button *btn = NULL;
guint timeout_id = 0;

/* Function to update progress */
gboolean update_progress(gpointer data) {
    static double value = 0.0;
    
    value += 0.05;  /* Increase by 5% each time */
    
    if (value >= 1.0) {
        value = 1.0;
        set_progress_value(pb, value);
        timeout_id = 0;
        return FALSE;  /* Stop the timer */
    }
    
    set_progress_value(pb, value);
    return TRUE;  /* Continue the timer */
}

/* Button click callback */
void on_button_click(GtkWidget *widget, gpointer data) {
    set_progress_value(pb, 0.0);  /* Reset to 0 */
    
    /* Start timer to update progress every 100ms */
    if (timeout_id) {
        g_source_remove(timeout_id);
    }
    timeout_id = g_timeout_add(100, update_progress, NULL);
}

int main() {
    /* Initialize GTK */
    ProgramStart();
    
    /* Create window */
    win = create_window();
    win->title = "Progress Bar Example";
    win->width = 400;
    win->height = 200;
    win->resizable = FALSE;
    
    /* Create vertical box */
    vbox = create_vbox(10, FALSE);
    vbox->margin_top = 20;
    vbox->margin_bottom = 20;
    vbox->margin_left = 20;
    vbox->margin_right = 20;
    update_box(vbox);
    
    /* Create progress bar */
    pb = create_progress_bar();
    pb->width = 300;
    pb->height = 30;
    pb->show_text = TRUE;  /* Show percentage text */
    update_progress_bar(pb);
    
    /* Create button */
    btn = create_button();
    btn->label = "Start Progress";
    btn->width = 150;
    btn->height = 40;
    btn->click_callback = on_button_click;
    update_button(btn);
    
    /* Add widgets to box */
    add_to_box(vbox, pb->progress);
    add_to_box(vbox, btn->button);
    
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