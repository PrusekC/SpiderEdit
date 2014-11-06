#include "main.h"

void showSaveFileDialog(GtkMenuItem *saveFileAs, fileData *data)
{

    if(data->tmpFileLocation.size() > 1)
    {
        ofstream file(data->tmpFileLocation.c_str());
        string bufferText;
        GtkTextIter startIter;
        GtkTextIter endIter;

        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &startIter);
        gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &endIter);
        bufferText = gtk_text_buffer_get_text(data->tmpTextBuffer, &startIter, &endIter, 1);

        file << bufferText;
        file.close();
    }
    else
    {
        GtkWidget *saveFileDialog;
        saveFileDialog = gtk_file_chooser_dialog_new("Save file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);

        gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(saveFileDialog), true);
        gtk_dialog_run(GTK_DIALOG(saveFileDialog));

        const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(saveFileDialog));
        string tmpLocationString(filename); // you cannot convert gchar to string by assignment

        ofstream file(filename);
        string bufferText;
        GtkTextIter startIter;
        GtkTextIter endIter;

        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &startIter);
        gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &endIter);
        bufferText = gtk_text_buffer_get_text(data->tmpTextBuffer, &startIter, &endIter, 1);

        file << bufferText;
        file.close();

        data->tmpFileLocation = tmpLocationString; // Save file location

        gtk_widget_destroy(saveFileDialog);
    }
}
