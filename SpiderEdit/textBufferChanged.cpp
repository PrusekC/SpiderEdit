#include "main.h"

void textBufferChanged(GtkTextBuffer *buffer, fileData *data)
{
    data->isSaved = false;
    string statusBarString;
    if(data->tmpFileLocation.size() > 1) // file was saved previously
    {
        statusBarString = data->tmpFileLocation + " *NOT SAVED*";
    }
    else
    {
        statusBarString = "New file *NOT SAVED*";
    }
    gtk_statusbar_push(GTK_STATUSBAR(data->tmpStatusBar), gtk_statusbar_get_context_id(GTK_STATUSBAR(data->tmpStatusBar), "info"), statusBarString.c_str());

}
