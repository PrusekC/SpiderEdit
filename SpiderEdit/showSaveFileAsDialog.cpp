#include "main.h"

void showSaveFileAsDialog(GtkMenuItem *saveFileAs, fileData *data)
{
    GtkWidget *saveFileDialog;
    saveFileDialog = gtk_file_chooser_dialog_new("Save file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);

    if (gtk_dialog_run(GTK_DIALOG(saveFileDialog)) == GTK_RESPONSE_ACCEPT)
    {
        gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(saveFileDialog), true);
        gtk_dialog_run(GTK_DIALOG(saveFileDialog));

        const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(saveFileDialog));

        ofstream file(filename);
        string bufferText;
        GtkTextIter startIter;
        GtkTextIter endIter;

        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &startIter);
        gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(data->tmpTextBuffer), &endIter);
        bufferText = gtk_text_buffer_get_text(data->tmpTextBuffer, &startIter, &endIter, 1);

        data->tmpFileLocation = filename;

        file << bufferText;
        file.close();

        gtk_widget_destroy(saveFileDialog);
    }
    data->isSaved = true;
    gtk_statusbar_push(GTK_STATUSBAR(data->tmpStatusBar), gtk_statusbar_get_context_id(GTK_STATUSBAR(data->tmpStatusBar), "info"), data->tmpFileLocation.c_str());
}
