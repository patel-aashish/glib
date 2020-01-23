/**
 * @file GHashTable_basic.c
 * @author Aashish Patel <aashish.a.patel@gmail.com>
 * @brief A program to illustrate basic ops of GHashTable
 * @version 0.1
 * @date 2020-01-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <glib.h>
#include <gmodule.h>

int main(int argc, char **argv) {
    gboolean found;
    GHashTable *hash = g_hash_table_new(g_str_hash, g_str_equal);
    /* hash, key, value */
    g_hash_table_insert(hash, "Maharashtra", "Mumbai");
    g_hash_table_insert(hash, "Telangana", "Hyderabad");
    g_hash_table_insert(hash, "Tamil Nadu", "Chennai");
    /* size of hash table */
    g_print("There are %d keys in the table\n", g_hash_table_size(hash));
    g_print("The capital of Telangana is %s\n", (char *)g_hash_table_lookup(hash, "Telangana"));
    /* Removing an element from the table */
    found = g_hash_table_remove(hash, "Tamil Nadu");
    g_print("The key 'Tamil Nadu' was %sfound and removed\n", found? "":"not ");
    /* releasing the hash table */
    g_hash_table_destroy(hash);
    return 0;
}