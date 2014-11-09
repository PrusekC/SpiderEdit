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

void spiderEditClose();
void showOpenFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, GtkTextBuffer *buffer);
