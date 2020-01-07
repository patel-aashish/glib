#include <glib.h>
#include <gmodule.h>

void print_iterator(gpointer item, gpointer prefix) {
    g_print("%s %s\n", (char *)prefix, (char *)item);
}

void print_iterator_simple(gpointer item) {
    g_print("%s\n", (char *)item);
}

int main(int argc, char **argv) {
    GSList *list = NULL;

    // Add elements to the list using g_strdup
    list = g_slist_append(list, g_strdup("one"));
    list = g_slist_append(list, g_strdup("two"));
    list = g_slist_append(list, g_strdup("three"));

    // Iterate using prefix
    g_print("Iterating with a function: \n");
    g_slist_foreach(list, print_iterator, "=>");
    // Iterate using simple function
    g_print("Iterating with a simple function: \n");
    g_slist_foreach(list, (GFunc)print_iterator_simple, NULL);
    // Free each element using g_slist_foreach
    g_print("Freeing each element of the list\n");
    g_slist_foreach(list, (GFunc)g_free, NULL);

    g_slist_free(list);
    return 0;
}