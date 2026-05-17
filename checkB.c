#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

window *win = NULL;
box *vbox = NULL;
check_button *chk = NULL;

void on_check_toggled(GtkWidget *widget, gpointer data) {
    if (is_check_button_active(chk)) {
        printf("Checkbox is checked!\n");
    } else {
        printf("Checkbox is unchecked!\n");
    }
}

int main() {
    ProgramStart();
    
    /* Window */
    win = create_window();
    win->title = "Simple Check";
    win->width = 250;
    win->height = 100;
    update_window(win);
    
    /* Box */
    vbox = create_vbox(10, FALSE);
    update_box(vbox);
    
    /* Check button */
    chk = create_check_button();
    chk->label = "Click me";
    chk->toggled_callback = on_check_toggled;
    update_check_button(chk);
    
    /* Add to window */
    add_to_box(vbox, chk->checkbutton);
    add_to_window(win, vbox->box);
    
    close_window(win);
    display_window(win);
    
    MainStart();
    ProgramEnd();
    return 0;
}