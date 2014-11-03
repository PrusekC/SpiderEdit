#include "main.h"

void showOpenFileDialog(GtkMenuItem *openFile, GtkTextBuffer *buffer)
{
    GtkWidget *openFileDialog;
    openFileDialog = gtk_file_chooser_dialog_new("Open file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    gtk_dialog_run(GTK_DIALOG(openFileDialog));

    const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(openFileDialog));

    ifstream file(filename);
    string line;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            line += "\n";
            GtkTextIter endOfTextInput;
            gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &endOfTextInput);
            gtk_text_buffer_insert(buffer, &endOfTextInput, line.c_str(), line.size());
        }
    }

    file.close();

    gtk_widget_destroy(openFileDialog);
}
