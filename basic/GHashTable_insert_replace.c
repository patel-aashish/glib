/**
 * @file GHashTable_insert_replace.c
 * @author Aashish Patel <aashish.a.patel@gmail.com>
 * @brief A program to illustrate difference between insert and replace in GHashTable
 * @version 0.1
 * @date 2020-01-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <glib.h>
#include <gmodule.h>

static char* telangana_1, *telangana_2;

/**
 * @brief Function to free memory associated with key
 * 
 * @param data, pointer to the key which is to be freed
 */
void key_destroyed(gpointer data) {
    g_print("Got a key destroy call for %s\n", (char *)data==telangana_1? "telangana_1" : "telangana_2");
}

int main(int argc, char **argv) {
    GHashTable *hash = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify)key_destroyed, NULL);

    telangana_1 = g_strdup("Telangana");
    telangana_2 = g_strdup("Telangana");

    g_hash_table_insert(hash, telangana_1, "Hyderabad");
    g_print("Calling insert with telangana_2 key\n");
    /* Only value will be replaced */
    g_hash_table_insert(hash, telangana_2, "Nirmal");
    g_print("Calling replace with telangana_2 key\n");
    g_hash_table_replace(hash, telangana_2, "Hyderabad");
    g_print("Destroying hash, so goodbye telangana_2 key\n");
    g_hash_table_destroy(hash);
    g_free(telangana_1);
    g_free(telangana_2);
    return 0;
}