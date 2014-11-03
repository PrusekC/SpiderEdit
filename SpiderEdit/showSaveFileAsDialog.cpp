#include "main.h"

void showSaveFileAsDialog(GtkMenuItem *saveFileAs, GtkTextBuffer *buffer)
{
    GtkWidget *saveFileDialog;
    saveFileDialog = gtk_file_chooser_dialog_new("Save file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);

    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(saveFileDialog), true);
    gtk_dialog_run(GTK_DIALOG(saveFileDialog));

    const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(saveFileDialog));


    ofstream file(filename);
    string bufferText;
    GtkTextIter startIter;
    GtkTextIter endIter;

    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &startIter);
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &endIter);
    bufferText = gtk_text_buffer_get_text(buffer, &startIter, &endIter, 1);

    file << bufferText;
    file.close();

    gtk_widget_destroy(saveFileDialog);
}
