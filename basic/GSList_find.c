#include <glib.h>
#include <gmodule.h>

gint custom_finder (gconstpointer item1) {
    return g_ascii_strcasecmp(item1, "two");
}

int main() {
    GSList *list = NULL, *item = NULL;
    // Add items to the list
    list = g_slist_append(list, "one");
    list = g_slist_append(list, "two");
    list = g_slist_append(list, "three");

    item = g_slist_find(list, "two");
    g_print("This item should be 'two': %s\n", (char *)item->data);
    // Using custom find function
    item = g_slist_find_custom(list, NULL, (GCompareFunc)custom_finder);
    g_print("Again, this item should be 'two' : %s\n", (char *)item->data);

    // If the item is not found then NULL is returned
    item = g_slist_find(list, "ten");
    g_print("'ten' is not in the list so we get : %s\n", item ? (char *)item->data:"(null)");
    g_slist_free(list);
    return 0;
}