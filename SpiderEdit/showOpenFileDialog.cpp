#include "main.h"

void showOpenFileDialog(GtkMenuItem *openFile, fileData *data)
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

    GtkWidget *openFileDialog;
    openFileDialog = gtk_file_chooser_dialog_new("Open file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

    if (gtk_dialog_run(GTK_DIALOG(openFileDialog)) == GTK_RESPONSE_ACCEPT)
    {
        const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(openFileDialog));
        string tmpLocationString(filename); // you cannot convert gchar to string by assignment

        ifstream file(filename);
        string line;
        if(file.is_open())
        {
            while(getline(file, line))
            {
                line += "\n";
                GtkTextIter endOfTextInput;
                gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &endOfTextInput);
                gtk_text_buffer_insert(data->tmpTextBuffer, &endOfTextInput, line.c_str(), line.size());
            }
        }

        file.close();

        data->tmpFileLocation = tmpLocationString; // Save file location
        gtk_statusbar_push(GTK_STATUSBAR(data->tmpStatusBar), gtk_statusbar_get_context_id(GTK_STATUSBAR(data->tmpStatusBar), "info"), tmpLocationString.c_str());

        gtk_widget_destroy(openFileDialog);
    }
}
