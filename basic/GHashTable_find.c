/**
 * @file GHashTable_find.c
 * @author Aashish Patel <aashish.a.patel@gmail.com>
 * @brief finding element in a GHashTable
 * @version 0.1
 * @date 2020-01-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief Callback function for freeing up value 
 * 
 * @param data, value pointer 
 */
void value_destroyed(gpointer data) {
    g_print("Got destroy for %d\n", GPOINTER_TO_INT(data));
}

/**
 * @brief Finder function for g_hash_table_find
 * 
 * @param key, pointer to key
 * @param value, pointer to value
 * @param user_data, pointer to user data passed
 */
gboolean finder (gpointer key, gpointer value, gpointer user_data) {
    return (GPOINTER_TO_INT(key) + GPOINTER_TO_INT(value) == 12);
}

int main() {
    GHashTable *hash = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)value_destroyed);
    gpointer item_ptr = NULL;
    gint item;
    g_hash_table_insert(hash, GINT_TO_POINTER(6), GINT_TO_POINTER(40));
    g_hash_table_insert(hash, GINT_TO_POINTER(2), GINT_TO_POINTER(10));
    g_hash_table_insert(hash, GINT_TO_POINTER(12), GINT_TO_POINTER(19));
    item_ptr = g_hash_table_find(hash, (GHRFunc)finder, NULL);
    item = GPOINTER_TO_INT(item_ptr);
    g_print("%d + %d == 12\n", item, 12-item);
    g_hash_table_destroy(hash);
    return 0;
}