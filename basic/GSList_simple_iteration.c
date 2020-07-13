#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GSList *list = NULL, *iterator = NULL;
    // Add elements to the list
    list = g_slist_append(list, "one");
    list = g_slist_append(list, "two");
    list = g_slist_append(list, "three");

    for (iterator = list; iterator; iterator = iterator->next) {
        g_print("Current item is %s \n", (char *)iterator->data);
    }

    g_slist_free(list);
    return 0;
}