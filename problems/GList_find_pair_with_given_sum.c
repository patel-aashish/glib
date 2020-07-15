/**
 * @file GList_find_pair_with_give_sum.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Given a doubly linked list, find a pair whose sum matches given value
 * @version 0.1
 * @date 2020-07-15
 *
 * @copyright Copyright (c) 2020 Aashish Patel
 *
 */
#include <glib.h>
#include <gmodule.h>
#include <string.h>

void print_iterator(gpointer item, gpointer prefix) {
  g_print(" %s %u ", (gchar *)prefix, GPOINTER_TO_UINT(item));
}

gint compare(gconstpointer a, gconstpointer b) {
  guint n1 = GPOINTER_TO_UINT(a);
  guint n2 = GPOINTER_TO_UINT(b);

  if (n1 < n2) {
    return -1;
  } else if (n1 > n2) {
    return 1;
  }

  return 0;
}

int main(int argc, char const *argv[])
{
  guint len, n1, n2, val;
  gint i;
  GList *list=NULL, *start=NULL, *end=NULL;
  gboolean found = FALSE;

  if (argc != 3) {
    g_print("Invalid number of arguments specified\n");
    g_print("Usage: ./GList_find_pair_with_given_sum <list> value\n");
    return -1;
  }

  len = strlen(argv[1]);
  val = atoi(argv[2]);

  for (i = 0; i < len; i++) {
    list = g_list_append(list, GUINT_TO_POINTER((guint)argv[1][i]-48));
  }

  g_print("%u", GPOINTER_TO_UINT(list->data));
  g_list_foreach(list->next, (GFunc)print_iterator, "<->");
  g_print("\n");

  list = g_list_sort(list, (GCompareFunc)compare);

  g_print("%u", GPOINTER_TO_UINT(list->data));
  g_list_foreach(list->next, (GFunc)print_iterator, "<->");
  g_print("\n");
  start = list;
  end = g_list_last(list);

  while (start != NULL && end != NULL &&
         start != end && end->next != start) {
    n1 = GPOINTER_TO_UINT(start->data);
    n2 = GPOINTER_TO_UINT(end->data);
    if (n1 + n2 == val) {
      found = TRUE;
      g_print("Found:(%u,%u)\n", n1, n2);
      start = start->next;
      end = end->prev;
    } else {
      if((n1+n2) < val) {
        start = start->next;
      } else {
        end = end->prev;
      }
    }
  }

  if (found == FALSE) {
    g_print("No pair found!!!\n");
  }

  return 0;
}
