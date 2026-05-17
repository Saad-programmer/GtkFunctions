#include "structures.h"

int main(int argc, char *argv[]) {
    ProgramStart();
    window *main_window = create_window();
    main_window->title = "Presentation ordinateur";
    main_window->width = 400;
    main_window->height = 300;
    update_window(main_window);

    menu *main_menu = create_horizontal_menu();
    add_menu_item(main_menu, "File", NULL, NULL);
    menu *edit_submenu = create_vertical_menu();
    add_menu_item(edit_submenu, "Cut", NULL, NULL);
    add_menu_item(edit_submenu, "Copy", NULL, NULL);
    add_menu_item(edit_submenu, "Paste", NULL, NULL);
    add_menu_item(main_menu, "Edit", NULL, NULL);
    add_menu_item(main_menu, "Edit", NULL, NULL);
    add_menu_item(main_menu, "View", NULL, NULL);
    add_menu_item(main_menu, "Exit", NULL, NULL);
    ADD_TO_WINDOW(main_window, main_menu->menu_widget);

    display_window(main_window);
    close_window(main_window);
    MainStart();
    return 0;
}