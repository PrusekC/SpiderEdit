#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct fileData{
    string tmpFileLocation;
    GtkWidget *tmpTextInput;
    GtkTextBuffer *tmpTextBuffer;
    GtkWidget *tmpStatusBar;
    bool isSaved;
    bool wrapWords;

    fileData(string location, GtkWidget *textInput, GtkTextBuffer *buffer, GtkWidget *statusBar)
    {
        tmpFileLocation = location;
        tmpTextInput = textInput;
        tmpTextBuffer = buffer;
        tmpStatusBar = statusBar;
        isSaved = true;
        wrapWords = false;
    }
};

void spiderEditClose(GtkMenuItem *quit, fileData *data);
void spiderEditCloseByX(GtkWindow *window, GdkEvent *event, fileData *data);

void newFileCreate(GtkMenuItem *newFile, fileData *data);
void showOpenFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileDialog(GtkMenuItem *saveFile, fileData *data);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, fileData *data);

void showAboutDialog(GtkMenuItem *about);

void textBufferChanged(GtkTextBuffer *buffer, fileData *data);
void wrapWordsToogled(GtkMenuItem *wrapWords, fileData *data);
