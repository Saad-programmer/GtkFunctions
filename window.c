#include "structures.h"


void openWindow(GtkWidget *widget, gpointer data) {
    
    window *Win = create_window();
    Win->icon_path="image.jpg";
    Win->height=200;
    Win->width=100;
    update_window(Win);
    box
    display_window(Win);
}

int main(){
    ProgramStart();

    window *Fenetre = create_window();
    Fenetre->icon_path="image.jpg";
    Fenetre->title = "Presentation";
    //Fenetre->bg_color="grey";
    Fenetre->height=600;
    Fenetre->width=500;
    update_window(Fenetre);
    

   
    box* MAIN_box = create_vbox(120,FALSE);
    add_to_window(Fenetre, MAIN_box->box);


    menu* main_menu = create_horizontal_menu();

    menu *file_menu = create_submenu();
    add_menu_item_with_icon(file_menu, "New", "document-new", NULL, NULL);
    add_menu_item_with_icon(file_menu, "Open", "document-open", NULL, NULL);
    add_menu_item_with_icon(file_menu, "Save", "document-save", NULL, NULL);
    add_menu_item_with_icon(file_menu, "Save As", "document-save-as", NULL, NULL);
    add_submenu(main_menu, "File", file_menu);

    
    menu *file_menu2 = create_submenu();
    add_menu_item_with_icon(file_menu2, "New", "document-new", NULL, NULL);
    add_menu_item_with_icon(file_menu2, "Open", "document-open", NULL, NULL);
    add_menu_item_with_icon(file_menu2, "Save", "document-save", NULL, NULL);
    add_menu_item_with_icon(file_menu2, "Save As", "document-save-as", NULL, NULL);

    add_submenu(main_menu, "EDIt", file_menu2);

    //add_to_box(MAIN_box,main_menu->menu_widget);
    add_to_box_with_properties(MAIN_box, main_menu->menu_widget , FALSE, FALSE, 0);
    

    box* SecondBoxH = create_hbox(0,FALSE);
    add_to_box(MAIN_box, SecondBoxH->box);

    //RADIO
    box* RadioBoxV = create_vbox(0,FALSE);
    add_to_box(SecondBoxH,RadioBoxV->box);
    label* TitreG1 = create_label();
    TitreG1->text = "Qualites des ordinateurs";
    update_label(TitreG1);
    add_to_box(RadioBoxV,TitreG1->label);

    box* hRBox = create_hbox(0,FALSE);
    add_to_box(RadioBoxV,hRBox->box);
    radio_button* TBonne = create_radio_button("PremierG","Tres Bonnne");
    TBonne->active = TRUE;
    update_radio_button(TBonne);

    radio_button* Moyenne = create_radio_button("PremierG","Moyenne");


    radio_button* Faible = create_radio_button("PremierG","Faible");

    add_to_box(hRBox,TBonne->radio_button);
    add_to_box(hRBox,Moyenne->radio_button);
    add_to_box(hRBox,Faible->radio_button);

    
    button* OK = create_button();
    OK->click_callback = openWindow;
    //OK->callback_data = Fenetre;
    update_button(OK);
    add_to_box(MAIN_box,OK->button);


    
    display_window(Fenetre);

    MainStart();
    return 0;
}