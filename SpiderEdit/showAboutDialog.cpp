#include "main.h"

void showAboutDialog(GtkMenuItem *about)
{
  GdkPixbuf *spiderEditIcon = gdk_pixbuf_new_from_file("icon.png", NULL);

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Patryk Cysarz");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "SpiderEdit - Simple text editor");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://prusekc.github.io/SpiderEdit/");
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), spiderEditIcon);
  g_object_unref(spiderEditIcon), spiderEditIcon = NULL;
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}
