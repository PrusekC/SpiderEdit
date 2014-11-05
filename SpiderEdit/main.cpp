#include "main.h"

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;

    // menu bar
    GtkWidget *menuBar;
    GtkWidget *file;
    GtkWidget *fileMenu;
    GtkWidget *edit;
    GtkWidget *help;

    // File submenu
    GtkWidget *newFile;
    GtkWidget *openFile;
    GtkWidget *saveFile;
    GtkWidget *saveFileAs;
    GtkWidget *quit;

    GtkWidget *textInput;
    GtkTextBuffer *textBuffer;

    // Others
    bool isSaved = true;
    string fileLocation = " ";
    gtk_init(&argc, &argv);

    // Create the window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "SpiderEdit");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create vbox
    vbox = gtk_vbox_new (FALSE, 2);
    gtk_container_add (GTK_CONTAINER (window), vbox);

    // Create menu bar
    menuBar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();

    // Menu labels
    file = gtk_menu_item_new_with_label("File");
    edit = gtk_menu_item_new_with_label("Edit");
    help = gtk_menu_item_new_with_label("Help");
    newFile = gtk_menu_item_new_with_label("New file");
    openFile = gtk_menu_item_new_with_label("Open file");
    saveFile = gtk_menu_item_new_with_label("Save file");
    saveFileAs = gtk_menu_item_new_with_label("Save file as ...");
    quit = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), fileMenu);

    // Organize menu
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), edit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), help);

    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), newFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveFileAs);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quit);

    gtk_box_pack_start(GTK_BOX(vbox), menuBar, 0, 0, 1);

    //Create text input field
    textInput = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX (vbox), textInput, 1, 1, 0);
    textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (textInput));

    fileData data(fileLocation, textBuffer);

    // Menu actions
    g_signal_connect(G_OBJECT(openFile), "activate", G_CALLBACK(showOpenFileDialog), &data);
    g_signal_connect(G_OBJECT(saveFile), "activate", G_CALLBACK(showSaveFileDialog), &data);
    g_signal_connect(G_OBJECT(saveFileAs), "activate", G_CALLBACK(showSaveFileAsDialog), textBuffer);
    g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(spiderEditClose), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
