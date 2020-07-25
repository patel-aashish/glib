/**
 * @file GHashTable_most_frequent_element_array.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Find the most frequent element in the array using GHashTable
 * @version 0.1
 * @date 2020-07-22
 *
 * @copyright Copyright (c) 2020 Aashish Patel
 *
 */
#include <glib.h>
#include <gmodule.h>


/**
 * @brief this is placeholder for max count element
 *
 */
typedef struct {
  gchar key;
  guint val;
} Element;

/**
 * @brief Get the most frequent element
 *
 * @param key
 * @param val
 * @param user_data
 */
void get_most_frequent (gpointer key,
                        gpointer val,
                        gpointer user_data)
{
  gint k = *(gint *)key;
  guint v = *(guint*)val;
  Element *e = (Element *)user_data;
  if (e->val < v)
  {
    e->val = v;
    e->key = k;
  }
}

/**
 * @brief Destroy the memory allocated for key
 *
 * @param kp
 */
void key_destroy (gpointer kp) {
  if (kp != NULL)
  {
    g_free((gint*)kp);
  }
}

/**
 * @brief Destroy the memory allocated for value
 *
 * @param vp
 */
void value_destroy (gpointer vp) {
  if (vp != NULL)
  {
    g_free((guint*)vp);
  }
}

int main(int argc, char const *argv[])
{
  GHashTable *hash = g_hash_table_new_full(g_int_hash,
                                           g_int_equal,
                                           key_destroy,
                                           value_destroy);

  if (argc != 2) {
      g_print("Invalid number of arguments!!\n");
      g_print("Usage: ./GHashTable_most_frequent <array>\n");
      return -1;
  }

  g_print("in:%s\n", argv[1]);
  gint key = 0;
  gint *kp = NULL;
  gpointer ptr = NULL;
  guint *vp = NULL;
  gchar *in_str = (gchar *)argv[1];
  while(*in_str) {
    key = *in_str;
    vp = NULL;
    ptr = g_hash_table_lookup(hash, &key);
    if (ptr == NULL) {
      kp = g_new0(gint, 1);
      *kp = key;
      vp = g_new0(guint, 1);
      *vp = 1;
      g_hash_table_insert(hash, kp, (gpointer)vp);
    } else {
      vp = (guint*)ptr;
      *vp = (*vp + 1);
    }
    in_str++;
  }

  Element *e = g_new0(Element, 1);
  g_hash_table_foreach(hash, (GHFunc)get_most_frequent, (gpointer)e);


  g_print("Most frequent element is %c, it occurred %u times\n", e->key, e->val);
  g_free(e);
  g_hash_table_destroy(hash);
  return 0;
}
