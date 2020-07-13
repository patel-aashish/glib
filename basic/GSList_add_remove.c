#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    // There is no function to create a new GSList
    GSList *list =NULL;
    // Add at tail
    list = g_slist_append(list, "last");
    // Add at head
    list = g_slist_prepend(list, "first");
    // Check length
    g_print("List has %d items\n", g_slist_length(list));
    // Remove item
    list = g_slist_remove(list, "first");
    // Check length
    g_print("List has %d items\n", g_slist_length(list));
    // Destroy list
    g_slist_free(list);
    return 0;
}