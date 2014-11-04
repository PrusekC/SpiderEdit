#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct fileData{
    string tmpFileLocation;
    GtkTextBuffer *tmpTextBuffer;

    fileData(string location, GtkTextBuffer *buffer)
    {
        tmpFileLocation = location;
        tmpTextBuffer = buffer;
    }
};

void spiderEditClose();
void showOpenFileDialog(GtkMenuItem *openFile, GtkTextBuffer *buffer);
void showSaveFileDialog(GtkMenuItem *openFile, fileData *data);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, GtkTextBuffer *buffer);
