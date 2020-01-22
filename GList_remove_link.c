#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GList *list=NULL, *link=NULL;
    list = g_list_append(list, "Mumbai ");
    list = g_list_append(list, "Delhi ");
    list = g_list_append(list, "Chennai ");
    list = g_list_append(list, "Hyderabad ");
    g_print("Here is the list: ");
    g_list_foreach(list, (GFunc)g_print, NULL);
    // Getting the link to the element at the index 1
    link = g_list_nth(list, 1);
    list = g_list_remove_link(list, link);
    // The linked element needs to be freed explicitly
    g_list_free_1(link);
    g_print("\nThe list after removing link: ");
    g_list_foreach(list, (GFunc)g_print, NULL);
    // Remove and free an element
    list = g_list_delete_link(list, g_list_nth(list, 1));
    g_print("\nThe list after removing link: ");
    g_list_foreach(list, (GFunc)g_print, NULL);
    g_print("\n");
    g_list_free(list);

    return 0;
}