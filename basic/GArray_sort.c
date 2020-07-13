/**
 * @file GArray_sort.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Sorting an GArray
 * @version 0.1
 * @date 2020-02-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief Display elements of GArray
 * 
 * @param a, GArray whose elements are to be displayed 
 */
void print_array(GArray *a) {
    int i;
    g_print("Array: ");
    for(i = 0; i < a->len; i++) {
        g_print("%d ", g_array_index(a, int, i));
    }
    g_print("\n");
}

/**
 * @brief function for comparing ints 
 * 
 * @param a, pointer to first int 
 * @param b, pointer to second int 
 * @return int, difference of the two 
 */
int compare_ints(gpointer a, gpointer b) {
    int x,y;
    x = *(int *) a;
    y = *(int *) b;

    return x-y;
}

int main() {
    int x[6] = {5, 4, 2, 3, 1, 6};
    GArray *arr = g_array_new(FALSE, FALSE, sizeof(int));

    g_array_append_vals(arr, &x, 6);
    print_array(arr);
    g_print("Sorting\n");
    g_array_sort(arr, (GCompareFunc)compare_ints);
    print_array(arr);
    g_array_free(arr, FALSE);
    return 0;
}