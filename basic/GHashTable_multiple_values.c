/**
 * @file GHashTable_multiple_values.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Adding multiple values to a single key
 * @version 0.1
 * @date 2020-01-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief prints values for each key
 * 
 * @param key, pointer to the key 
 * @param value, pointer to the value
 * @param data, pointer to the user data passed 
 */
void print(gpointer key, gpointer value, gpointer data) {
    g_print("Here are some cities in %s: ", (char *)key);
    g_slist_foreach((GSList *)value, (GFunc)g_print, NULL);
    g_print("\n");
}

/**
 * @brief destroys list associated with key 
 * 
 * @param key, pointer to the key 
 * @param value, pointer to the value 
 * @param data, pointer to the user data passed 
 */
void destroy(gpointer key, gpointer value, gpointer data) {
    GSList *list = (GSList *) value;
    g_print("Freeing GSList, first item is %s \n", (char *)list->data);
    g_slist_free(list);
}

int main() {
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(hash, "Maharashtra", g_slist_append(g_hash_table_lookup(hash, "Maharashtra"), "Mumbai "));
    g_hash_table_insert(hash, "Maharashtra", g_slist_append(g_hash_table_lookup(hash, "Maharashtra"), "Pune "));
    g_hash_table_insert(hash, "Punjab", g_slist_append(g_hash_table_lookup(hash, "Punjab"), "Chandigarh "));
    g_hash_table_insert(hash, "Punjab", g_slist_append(g_hash_table_lookup(hash, "Punjab"), "Amritsar "));

    g_hash_table_foreach(hash, print, NULL);
    // Destroy value list
    g_hash_table_foreach(hash, destroy, NULL);

    g_hash_table_destroy(hash);

    return 0;
}