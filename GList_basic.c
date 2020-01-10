#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GList *list = NULL, *other_list = NULL;
    list = g_list_append(list, "Mumbai ");
    g_print("First item is %s\n", (char *)list->data);
    list = g_list_insert(list, "Chennai ", 1);
    g_print("Second item is %s\n", (char *)g_list_nth_data(list, 1));
    list = g_list_remove(list, "Mumbai ");
    g_print("After removal of 'Mumbai', the length of list is %d\n", g_list_length(list));
    other_list = g_list_append(other_list, "Mumbai ");
    list = g_list_concat(list, other_list);
    g_print("After concatinating list is \n");
    g_list_foreach(list, (GFunc)g_print, NULL);
    g_print("\n");
    list = g_list_reverse(list);
    g_print("After reversing the list is \n");
    g_list_foreach(list, (GFunc)g_print, NULL);
    g_print("\n");
    g_list_free(list);
    g_list_free(other_list);

    return 0;
}