#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

/* Global variables */
window *win = NULL;
box *vbox = NULL;
image *img = NULL;
label *info = NULL;

int main() {
    /* Initialize GTK */
    ProgramStart();
    
    /* Create window */
    win = create_window();
    win->title = "Simple Image Display";
    win->width = 350;
    win->height = 350;
    update_window(win);
    
    /* Create vertical box */
    vbox = create_vbox(15, FALSE);
    vbox->margin_top = 20;
    vbox->margin_bottom = 20;
    vbox->margin_left = 20;
    vbox->margin_right = 20;
    update_box(vbox);
    
    /* Create image from an icon (no file needed) */
    img = create_image();
    img->icon_name = "face-smile";  /* GTK built-in icon */
    img->file_name = "image.jpg";  /* This will be ignored since icon_name is set */
    img->width = 400;
    img->height = 300;
    img->position = "center";
    update_image(img);
    
    /* Create info label */
    info = create_label();
    info->text = "This is a smiley icon\n(from GTK built-in icons)";
    info->color = "#0066cc";
    info->position = "center";
    update_label(info);
    
    /* Add to box */
    add_to_box(vbox, img->image);
    add_to_box(vbox, info->label);
    
    /* Add to window */
    add_to_window(win, vbox->box);
    
    /* Close handler */
    close_window(win);
    
    /* Display */
    display_window(win);
    MainStart();
    ProgramEnd();
    
    return 0;
}