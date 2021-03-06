#include "main.h"
#include <gdk-pixbuf/gdk-pixbuf.h>

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *scrolledWindow;
    GtkWidget *vbox;
    GtkWidget *statusBar;

    // menu bar
    GtkWidget *menuBar;
    GtkWidget *file;
    GtkWidget *fileMenu;
    GtkWidget *edit;
    GtkWidget *editMenu;
    GtkWidget *help;
    GtkWidget *helpMenu;

    // File submenu
    GtkWidget *newFile;
    GtkWidget *openFile;
    GtkWidget *saveFile;
    GtkWidget *saveFileAs;
    GtkWidget *quit;

    // Edit submenu
    GtkWidget *wrapWords;

    // Help submenu
    GtkWidget *about;

    // Text input
    GtkWidget *textInput;
    GtkTextBuffer *textBuffer;

    // Others
    string fileLocation = " ";


    gtk_init(&argc, &argv);

    // Create the window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "SpiderEdit");
    gtk_window_set_icon(GTK_WINDOW(window), gdk_pixbuf_new_from_file("icon.png", NULL));
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    statusBar = gtk_statusbar_new();

    scrolledWindow = gtk_scrolled_window_new(NULL, NULL);

    // Create vbox
    vbox = gtk_vbox_new (FALSE, 2);
    gtk_container_add (GTK_CONTAINER (window), vbox);

    // Create menu bar
    menuBar = gtk_menu_bar_new();
    fileMenu = gtk_menu_new();
    editMenu = gtk_menu_new();
    helpMenu = gtk_menu_new();

    // Menu labels
    file = gtk_menu_item_new_with_label("File");
    edit = gtk_menu_item_new_with_label("Edit");
    help = gtk_menu_item_new_with_label("Help");

    newFile = gtk_menu_item_new_with_label("New file");
    openFile = gtk_menu_item_new_with_label("Open file");
    saveFile = gtk_menu_item_new_with_label("Save file");
    saveFileAs = gtk_menu_item_new_with_label("Save file as ...");
    quit = gtk_menu_item_new_with_label("Quit");

    wrapWords = gtk_check_menu_item_new_with_label("Wrap words");

    about = gtk_menu_item_new_with_label("About");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), fileMenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editMenu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpMenu);

    // Organize menu
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), edit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuBar), help);

    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), newFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveFileAs);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quit);

    gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), wrapWords);

    gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu), about);

    gtk_box_pack_start(GTK_BOX(vbox), menuBar, 0, 0, 0);

    //Create text input field inside scrolledWindow
    textInput = gtk_text_view_new();
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox), scrolledWindow, 1, 1, 0);

    gtk_container_add(GTK_CONTAINER(scrolledWindow), textInput);
    textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (textInput));

    // set statusbar
    gtk_statusbar_push(GTK_STATUSBAR(statusBar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusBar), "info"), "New file");
    gtk_box_pack_start(GTK_BOX(vbox), statusBar, 0, 0, 0);

    // create struct with currently opened file datas
    fileData data(fileLocation, textInput, textBuffer, statusBar);

    // Menu actions
    g_signal_connect(G_OBJECT(newFile), "activate", G_CALLBACK(newFileCreate), &data);
    g_signal_connect(G_OBJECT(openFile), "activate", G_CALLBACK(showOpenFileDialog), &data);
    g_signal_connect(G_OBJECT(saveFile), "activate", G_CALLBACK(showSaveFileDialog), &data);
    g_signal_connect(G_OBJECT(saveFileAs), "activate", G_CALLBACK(showSaveFileAsDialog), &data);
    g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(spiderEditClose), &data);

    g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(showAboutDialog), NULL);

    // TextBuffer changed
    g_signal_connect(G_OBJECT(textBuffer), "changed", G_CALLBACK(textBufferChanged), &data);

    // Wrap words menu item clicked
    g_signal_connect(G_OBJECT(wrapWords), "toggled", G_CALLBACK(wrapWordsToogled), &data);

    // User closed app by clicking red X mark on title bar
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(spiderEditCloseByX), &data);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
