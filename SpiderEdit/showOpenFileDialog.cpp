#include "main.h"

void showOpenFileDialog(GtkMenuItem *openFile, fileData *data)
{
    GtkWidget *openFileDialog;
    openFileDialog = gtk_file_chooser_dialog_new("Open file", GTK_WINDOW(NULL), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    gtk_dialog_run(GTK_DIALOG(openFileDialog));

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

    gtk_widget_destroy(openFileDialog);
}
