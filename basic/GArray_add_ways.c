/**
 * @file GArray_add_ways.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Different ways of adding elements in GArray
 * @version 0.1
 * @date 2020-01-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief Print array elements
 * 
 * @param a, GArray whose elements are to be printed
 */
void print_array(GArray *a) {
    g_print("Array: ");
    int i;
    for(i = 0; i < a->len; i++) {
        g_print("%d ", g_array_index(a, int, i));
    }
    g_print("\n");
}

int main() {
    int x[2] = {4, 5};
    int y[2] = {2, 3};
    int z = 1;

    GArray *a = g_array_new(FALSE, FALSE, sizeof(int));
    g_print("Array is empty, lets add some values\n");
    g_array_append_vals(a, &x, 2);
    print_array(a);
    g_print("Now, prepending some values\n");
    g_array_prepend_vals(a, &y, 2);
    print_array(a);
    g_print("Prepend single value\n");
    g_array_prepend_val(a, z);
    print_array(a);

    g_array_free(a, FALSE);

    return 0;
}
