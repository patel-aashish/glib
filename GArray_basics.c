/**
 * @file GArray_basics.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief GArray basics, creation, adding elements, deletion
 * @version 0.1
 * @date 2020-01-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

int main() {
    GArray *a = g_array_new(FALSE, FALSE, sizeof(char *));
    char *one = "Hello";
    char *two = "there";
    char *three = "world";

    g_array_append_val(a, one);
    g_array_append_val(a, two);
    g_array_append_val(a, three);

    g_print("There are now %d items in the array\n", a->len);
    g_print("The first element is %s\n", g_array_index(a, char*, 0));
    g_print("The third element is %s\n", g_array_index(a, char*, 2));
    g_array_remove_index(a, 1);
    g_print("There are now %d items in the array\n", a->len);

    g_array_free(a, FALSE);
    return 0;
}