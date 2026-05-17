#include "structures.h"

int main() {
    ProgramStart();

    window *main_window = create_window();
    main_window->title = "Spinner Example";
    main_window->width = 400;
    main_window->height = 300;
    main_window->resizable = TRUE;
    update_window(main_window);

    spinner *spin = create_spinner();
    spin->text = "Loading...";
    spin->width = 100;
    spin->height = 100;
    update_spinner(spin);

    add_to_window(main_window, spin->container);
    display_window(main_window);

    start_spinner(spin);

    close_window(main_window);
    MainStart();
    return 0;
}