#include "structures.h"

int main(){
    ProgramStart();

    window *main_window = create_window();
    main_window->title = " Button Example ";
    main_window->resizable = TRUE;
    update_window(main_window);

    button *btn = create_button();
    btn->label = "Click Me!";
    btn->bg_color = "#121212"; // Green background
    btn->label_style = "color: white; font-size: 16px;";
    btn->width = 150;
    btn->height = 50;
    btn->callback_data = NULL;
    update_button(btn);

    add_to_window(main_window, btn->button);
    display_window(main_window);
    close_window(main_window);
    MainStart();
    return 0;
}