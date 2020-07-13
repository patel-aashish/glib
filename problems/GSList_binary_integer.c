/**
 * @file GSList_binary_integer.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Program to convert binary to decimal using GSList
 * @version 0.1
 * @date 2020-07-13
 * 
 * @copyright Copyright (c) 2020 Aashish Patel
 * 
 */
#include <glib.h>
#include <gmodule.h>
#include <string.h>

void print_iterator(gpointer item, gpointer prefix) {
  g_print("%s %u ", (char *)prefix, GPOINTER_TO_UINT(item));
}

guint power(guint b, guint p) {
  gint i = 0;
  guint prod = 1;
  for(i = 0; i < p; i++) {
    prod *= b;
  }
  return prod;
}

int main(int argc, char const *argv[])
{
  guint len = 0, p = 0;
  GSList *list = NULL, *iter=NULL;
  gint i;
  guint sum = 0;
  if (argc != 2) {
    g_print("Invalid number of argumensts specified\n");
    g_print("Usage: ./GSList_binary_integer <binary number to be converted>\n");
    return -1;
  }

  len = strlen(argv[1]);

  for(i = 0; i < len; i++) {
    list = g_slist_append(list, GUINT_TO_POINTER((guint)argv[1][i]-48));
  }

  g_slist_foreach(list, (GFunc)print_iterator, "=>");
  g_print("\n");

  p = len-1;
  for(iter=list; iter; iter=iter->next) {
    sum += power(2,p) * GPOINTER_TO_UINT(iter->data);
    p -= 1;
  }

  g_print("Decimal: %u\n", sum);
  return 0;
}
