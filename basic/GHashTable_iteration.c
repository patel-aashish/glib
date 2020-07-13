/**
 * @file GHashTable_iteration.c
 * @author Aashish Patel <aashish.a.patel@gmail.com>
 * @brief A program to iterate over a key/value pair in GHashTable
 * @version 0.1
 * @date 2020-01-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include<glib.h>
#include<gmodule.h>

/**
 * @brief function to print key value pair
 * 
 * @param key
 * @param value 
 * @param user_data, format string 
 */
void iterator(gpointer key, gpointer value, gpointer user_data) {
    g_print((char*)user_data, *(gint*)key, (char *)value);
}

int main(int argc, char **argv) {
    GHashTable *hash = g_hash_table_new(g_int_hash, g_int_equal);
    // Allocate memory for the keys
    gint *k_one = g_new(gint, 1);
    gint *k_two = g_new(gint,2);
    gint *k_three = g_new(gint,3);

    *k_one = 1;
    *k_two = 2;
    *k_three = 3;

    g_hash_table_insert(hash, k_one, "one");
    g_hash_table_insert(hash, k_two, "four");
    g_hash_table_insert(hash, k_three, "nine");

    g_hash_table_foreach(hash, (GHFunc)iterator, "The square of %d is %s\n");
    g_hash_table_destroy(hash);
    g_free(k_one);
    g_free(k_two);
    g_free(k_three);

    return 0;
}