#include <glib.h>
#include <gmodule.h>

int main (int argc, char **argv) {
    GSList *list = NULL;

    list = g_slist_append(list, "first");
    list = g_slist_append(list, "second");
    list = g_slist_append(list, "second");
    list = g_slist_append(list, "second");
    list = g_slist_append(list, "third");

    g_print("List has %d items \n", g_slist_length(list));

    // Remove first occurrence of second
    list = g_slist_remove(list, "second");
    g_print("List has %d items \n", g_slist_length(list));
    list = g_slist_remove(list, "second");
    // Remove first occurrence of second
    g_print("List has %d items \n", g_slist_length(list));
    g_slist_free(list);
    return 0;
}