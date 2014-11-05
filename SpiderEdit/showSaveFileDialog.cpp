#include "main.h"

void showSaveFileDialog(GtkMenuItem *saveFileAs, fileData *data)
{

    if(data->tmpFileLocation->size() > 1)
    {
        ofstream file(data->tmpFileLocation->c_str());
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
        cout << "Okno dialogowe zapisywania";
    }
}
