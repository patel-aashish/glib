/**
 * @file GHashTable_steal.c
 * @author Aashish Patel <aashish.a.patel@gmail.com>
 * @brief Program to illustrate stealing in hash table
 * @version 0.1
 * @date 2020-01-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

/**
 * @brief A validation function for g_hash_table_foreach_steal 
 * 
 * @param key, pointer to the key 
 * @param value, pointer to the value
 * @param user_data, pointer to the user data 
 * @return gboolean, here we always return TRUE 
 */
gboolean wide_open(gpointer key, gpointer value, gpointer user_data) {
    return TRUE;
}

/**
 * @brief Destroy notification callback
 * 
 * @param data, user data pointer 
 */
void destroyed(gpointer data) {
    g_print("Got a destroy callback for %s\n", (char *)data);
}

int main() {
    GHashTable *hash = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify)destroyed, (GDestroyNotify)destroyed);
    g_hash_table_insert(hash, "Gujarat", "Ahemadabad");
    g_hash_table_insert(hash, "Punjab", "Chandigarh");
    g_hash_table_insert(hash, "Rajasthan", "Jaipur");
    g_hash_table_insert(hash, "Maharashtra", "Mumbai");
    g_hash_table_insert(hash, "Telangana", "Hyderabad");
    g_print("Removing 'Rajasthan' we should see 2 destroy prints\n");
    g_hash_table_remove(hash, "Rajasthan");
    if(g_hash_table_steal(hash, "Punjab")) {
        g_print("'Punjab' has been stolen, %d items remaining\n", g_hash_table_size(hash));
    }
    g_print("Stealing remaining items\n");
    g_hash_table_foreach_steal(hash, (GHRFunc)wide_open, NULL);
    g_print("Destroying hash table but its empty so no callbacks\n");
    g_hash_table_destroy(hash);
    return 0;
}