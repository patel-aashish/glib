#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GSList *list1 = NULL;
    GSList *list2 = NULL;
    GSList *combined = NULL;
    GSList *reversed = NULL;

    // Adding few elements to the list 1
    list1 = g_slist_append(list1, "one");
    list1 = g_slist_append(list1, "two");
    // Adding few elements to the list 2
    list2 = g_slist_append(list2, "three");
    list2 = g_slist_append(list2, "four");

    // Combining the lists
    combined = g_slist_concat(list1, list2);

    // Reversing the combined list
    reversed = g_slist_reverse(combined);

    g_print("First item of reversed list is %s\n", (char *)reversed->data);

    g_slist_free(reversed);
    return 0;
}