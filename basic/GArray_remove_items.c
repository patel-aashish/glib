/**
 * @file GArray_remove_items.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Different ways of removing items from an GArray
 * @version 0.1
 * @date 2020-02-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief Print the elements of the GArray
 * 
 * @param a, GArray whose elements are to be displayed 
 */
void print_array(GArray *a) {
    int i;    
    g_print("Arrays: ");
    for(i = 0; i < a->len; i++) {
        g_print("%d ", g_array_index(a, int, i));
    }
    g_print("\n");
}

int main() {
    int x[6] = {1,2,3,4,5,6};
    GArray *arr = g_array_new(FALSE, FALSE, sizeof(int));
    g_array_append_vals(arr,&x, 6);
    print_array(arr);
    g_print("Removing the first item\n");
    g_array_remove_index(arr, 0);
    print_array(arr);
    g_print("Removing first 2 items\n");
    g_array_remove_range(arr, 0, 2);
    print_array(arr);
    g_print("Removing first element very quickly\n");
    // Does not preserve order, just removes
    g_array_remove_index_fast(arr, 0);
    print_array(arr);

    g_array_free(arr, FALSE);
    return 0;
}