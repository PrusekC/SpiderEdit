#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct fileData{
    string tmpFileLocation;
    GtkTextBuffer *tmpTextBuffer;
    GtkWidget *tmpStatusBar;
    bool isSaved;

    fileData(string location, GtkTextBuffer *buffer, GtkWidget *statusBar)
    {
        tmpFileLocation = location;
        tmpTextBuffer = buffer;
        tmpStatusBar = statusBar;
        isSaved = true;
    }
};

void spiderEditClose(GtkMenuItem *quit, fileData *data);
void spiderEditCloseByX(GtkWindow *window, GdkEvent *event, fileData *data);

void newFile(GtkMenuItem *newFile, fileData *data);
void showOpenFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileDialog(GtkMenuItem *saveFile, fileData *data);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, fileData *data);

void textBufferChanged(GtkTextBuffer *buffer, fileData *data);
