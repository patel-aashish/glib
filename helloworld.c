#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GList* list = NULL;
    list = g_list_append(list, "Hello world!!!");
    g_print("The first element in the list is, %s\n", (gchar *) g_list_first(list)->data);
    return 0;
}