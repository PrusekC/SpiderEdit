#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void spiderEditClose();
void showOpenFileDialog(GtkMenuItem *openFile, GtkTextBuffer *buffer);
void showSaveFileAsDialog(GtkMenuItem *saveFileAs, GtkTextBuffer *buffer);
