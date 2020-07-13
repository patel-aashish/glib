#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GList *list=NULL, *link=NULL;
    list = g_list_append(list, "Chennai ");
    list = g_list_append(list, "Chennai ");
    list = g_list_append(list, "Hyderabad ");
    list = g_list_append(list, "Delhi ");
    g_print("Here is the list: ");
    g_list_foreach(list, (GFunc)g_print, NULL);
    g_print("\nChennai is at index: %d\n", g_list_index(list, "Chennai "));
    g_print("\nMumbai is at index: %d\n", g_list_index(list, "Mumbai "));
    link = g_list_last(list);
    g_print("\nDelhi is at index: %d\n", g_list_position(list, link));

    g_print("\n");

    g_list_free(list);
    return 0;
}