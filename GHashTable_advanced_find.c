/**
 * @file GHashTable_advanced_find.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Finding key and value both in an GHashTable
 * @version 0.1
 * @date 2020-01-29
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

int main() {
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);
    char *state = NULL;
    char *capital = NULL;
    char **state_ptr=&state, **capital_ptr= &capital;
    gboolean result = FALSE;
    g_hash_table_insert(hash, "Maharashtra", "Mumbai");
    g_hash_table_insert(hash, "Telangana", "Hyderabad");
    g_hash_table_insert(hash, "Gujarat", "Gandhi Nagar");
    result = g_hash_table_lookup_extended(hash, "Gujarat", (gpointer *)state_ptr, (gpointer *)capital_ptr);
    if (result) {
        g_print("Found that the capital of %s is %s\n", state, capital);
    }

    if(!g_hash_table_lookup_extended(hash, "Karnataka", (gpointer *)state_ptr, (gpointer *)capital_ptr)) {
        g_print("Could not find capital of state Karnataka\n");
    }

    g_hash_table_destroy(hash);
    return 0;
}

