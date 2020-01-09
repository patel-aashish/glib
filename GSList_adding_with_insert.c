#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    GSList *list=NULL;
    list = g_slist_append(list, "Delhi ");
    list = g_slist_append(list, "Mumbai ");
    g_print("Before inserting 'Chennai' second item is : %s\n", (char *)g_slist_nth_data(list, 1));
    list = g_slist_insert(list, "Chennai ", 1);
    g_print("After inserting 'Chennai' second item is : %s\n", (char *)g_slist_nth_data(list, 1));
    list = g_slist_insert_before(list, g_slist_nth(list, 2), "Kolkata ");
    g_print("After insert before the third item is : %s\n", (char *)g_slist_nth_data(list, 2));
    list = g_slist_insert_sorted(list, "Hyderabad ",(GCompareFunc)g_ascii_strcasecmp);
    g_print("After sorted insert the final list is :\n");
    g_slist_foreach(list, (GFunc)g_print, NULL);
    g_print("\n");
    g_slist_free(list);
    return 0;
}