/**
 * @file GArray_insert_ways.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Different ways of inserting elements in an GArray
 * @version 0.1
 * @date 2020-01-31
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief Print elements of GArray
 * 
 * @param a, GArray whose elements are to be printed 
 */
void print_array(GArray *a) {
    int i;
    g_print("Array: ");
    for(i = 0; i < a->len; i++) {
        g_print("%d ", g_array_index(a, int, i));
    }
    g_print("\n");
}

int main() {
    int x[2] = {1,5};
    int y[2] = {3,4};
    int b = 2;
    GArray *a = g_array_new(FALSE, FALSE, sizeof(int));
    g_print("The array is empty, lets add some values\n");
    g_array_append_vals(a, &x, 2);
    print_array(a);
    g_print("Inserting 2 at index 1\n");
    g_array_insert_val(a, 1, b);
    print_array(a);
    g_print("Inserting {3,4} at index 2\n");
    g_array_insert_vals(a, 2, &y, 2);
    print_array(a);

    g_array_free(a, FALSE);

    return 0;
}