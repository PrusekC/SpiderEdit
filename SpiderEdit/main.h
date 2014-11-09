#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct fileData{
    string tmpFileLocation;
    GtkTextBuffer *tmpTextBuffer;
    bool isSaved;

    fileData(string location, GtkTextBuffer *buffer)
    {
        tmpFileLocation = location;
        tmpTextBuffer = buffer;
        isSaved = true;
    }
};

void spiderEditClose();
void showOpenFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, GtkTextBuffer *buffer);
