#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GList *list= NULL, *last = NULL;
    list = g_list_append(list, "one");
    list = g_list_append(list, "two");
    list = g_list_append(list, "three");
    g_print("The list is -> ");
    g_list_foreach(list, (GFunc)g_print, NULL);

    last = g_list_last(list);
    g_print("\nThe last element is %s \n", (char *)g_list_first(list)->data);
    g_print("The next to last element is %s\n", (char *)(last->prev->data));
    g_print("THe 2 elements before last element is %s\n", (char *)g_list_nth_prev(last, 2)->data);


    g_list_free(list);

    return 0;
}