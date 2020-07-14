/**
 * @file GSList_add_two_numbers.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Add two numbers stored in two GSList.
 *        1->2->3->4  => 1234
 *        +  5->6->7  => 567
 *        ----------
 *        1->8->0->1  => 1801
 * @version 0.1
 * @date 2020-07-14
 * 
 * @copyright Copyright (c) 2020 Aashish Patel
 * 
 */

#include<glib.h>
#include <gmodule.h>
#include <string.h>

void print_iterator(gpointer item, gpointer prefix) {
  g_print("%u", GPOINTER_TO_UINT(item));
}

int main(int argc, char const *argv[])
{
  GSList *num1 = NULL, *num2 = NULL;
  GSList *result = NULL;
  gint i = 0;
  guint n1 = 0, n2 = 0, sum = 0, carry = 0;
  guint len1 = 0, len2 = 0;
  if (argc != 3) {
    g_print("Invalid number of arguments specified\n");
    g_print("Usage: ./GSList_add_two_numbers <number 1> <number 2>\n");
    return -1;
  }

  len1 = strlen(argv[1]);
  len2 = strlen(argv[2]);

  for (i = 0; i < len1; i++) {
    num1 = g_slist_append(num1, GUINT_TO_POINTER((guint)argv[1][i] - 48));
  }

  for (i = 0; i < len2; i++) {
    num2 = g_slist_append(num2, GINT_TO_POINTER((guint)argv[2][i] - 48));
  }

  g_print("num1:");
  g_slist_foreach(num1, (GFunc)print_iterator, "->");
  g_print("\n");

  g_print("num2:");
  g_slist_foreach(num2, (GFunc)print_iterator, "->");
  g_print("\n");

  len1--;
  len2--;
  carry = 0;
  i = len1 > len2 ? len1 : len2;
  while(i >= 0) {
    n1 = 0;
    n2 = 0;
    if (len1 >= 0) {
      n1 = GPOINTER_TO_UINT(g_slist_nth_data(num1, len1));
    }

    if (len2 >= 0) {
      n2 = GPOINTER_TO_UINT(g_slist_nth_data(num2, len2));
    }
    sum = n1 + n2 + carry;
    carry = sum / 10;
    result = g_slist_prepend(result, GUINT_TO_POINTER(sum%10));
    len1--;
    len2--;
    i--;
  }
  
  g_print("sum:");
  g_slist_foreach(result, (GFunc)print_iterator, NULL);
  g_print("\n");

  return 0;
}
