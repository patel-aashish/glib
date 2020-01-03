#include <glib.h>
#include <gmodule.h>

int main (int argc, char **argv) {
    GSList *list = NULL;
    list = g_slist_append(list, "one");
    list = g_slist_append(list, "two");
    list = g_slist_append(list, "three");

    /* Last item access */
    g_print("The last item is %s \n", (char*)(g_slist_last(list)->data));
    /* The item at index 1 */
    g_print("The item at index 1 is %s \n", (char *)(g_slist_nth(list, 1)->data));
    g_print("The item at index 2 is %s \n", (char *)g_slist_nth_data(list, 2));

    /* The item after first item can also be accessed as */
    g_print("The item after the first item is %s \n", (char *)(g_slist_next(list)->data));

    g_slist_free(list);
    return 0;
}