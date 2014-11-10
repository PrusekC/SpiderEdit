#include "main.h"

void newFileCreate(GtkMenuItem *newFile, fileData *data)
{
    if(data->isSaved != true) // ask if user want to save current file
    {
        GtkWidget *saveQuestion;
        saveQuestion = gtk_message_dialog_new(GTK_WINDOW(NULL), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO, "Do you want to save your current file?");
        gtk_window_set_title(GTK_WINDOW(saveQuestion), "Save?");

        if(gtk_dialog_run(GTK_DIALOG(saveQuestion)) == -8) // user clicked "yes", show save file dialog
        {
            showSaveFileDialog(NULL, data);
        }
        gtk_widget_destroy(saveQuestion);
    }

    gtk_text_buffer_set_text(data->tmpTextBuffer, "", 0); // clear text buffer
    data->tmpFileLocation = "";
    data->isSaved = true;
    gtk_statusbar_push(GTK_STATUSBAR(data->tmpStatusBar), gtk_statusbar_get_context_id(GTK_STATUSBAR(data->tmpStatusBar), "info"), "New file");
}
