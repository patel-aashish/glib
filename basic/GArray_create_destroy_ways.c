/**
 * @file GArray_create_destroy_ways.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Different ways of creating and destroying an array
 * @version 0.1
 * @date 2020-01-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

int main() {
    // Creates a GArray with size of 16 and inits each of them to 0
    GArray *a = g_array_sized_new(TRUE, TRUE, sizeof(int), 16);
    char *x = g_strdup("hello world");
    g_print("Array preallocation is hidden so the size is %d\n", a->len);
    g_print("Array was init'd to zero, so the third element is %d\n", g_array_index(a, int, 2));

    g_array_free(a, FALSE);

    // Creates an empty array and then resizes it to 16
    a = g_array_new(FALSE, FALSE, sizeof(char));
    g_array_set_size(a, 16);
    g_array_free(a, FALSE);

    a = g_array_new(FALSE, FALSE, sizeof(char));
    g_array_append_val(a, x);
    // Frees memory associated with the element as well
    g_array_free(a, TRUE);

    return 0;
}