#include <glib.h>
#include <gmodule.h>

gint list_compare(gconstpointer item1, gconstpointer item2) {
    return g_ascii_strcasecmp(item1, item2);
}

int main(int argc, char **argv) {
    GSList *list = NULL;

    // Adding elements to the list
    list = g_slist_append(list, "Mumbai");
    list = g_slist_append(list, "Delhi");
    list = g_slist_append(list, "Chennai");
    list = g_slist_append(list, "Kolkata");

    // Sorting the list
    list = g_slist_sort(list, (GCompareFunc)list_compare);
    // we can also pass the g_ascii_strcasecmp directly to the sort function
    g_print("First element after sort is %s\n", (char *)list->data);
    g_print("Last element after sort is %s\n", (char *)(g_slist_last(list)->data));

    g_slist_free(list);
    return 0;
}