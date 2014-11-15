#include "main.h"

void wrapWordsToogled(GtkMenuItem *wrapWords, fileData *data)
{
    if(data->wrapWords == false)
    {
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(data->tmpTextInput), GTK_WRAP_WORD);
        data->wrapWords = true;
    }
    else
    {
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(data->tmpTextInput), GTK_WRAP_NONE);
        data->wrapWords = false;
    }
}
