/**
 * @file GList_priority_queue.c
 * @author Aashish Patel (aashish.a.patel@gmail.com)
 * @brief Priority queue using GList, supported ops:push,pop, peek, top
 * @version 0.1
 * @date 2020-07-16
 *
 * @copyright Copyright (c) 2020 Aashish Patel
 *
 */
#include <glib.h>
#include <gmodule.h>
#include <string.h>

/**
 * @brief Wrapper for our queue
 *
 */
typedef struct {
  guint data;
  guint priority;
} Element;

/**
 * @brief prints list elements
 *
 * @param item , node data
 * @param prefix , prefix to be printed before data
 */
void print_iterator(gpointer item, gpointer prefix) {
  Element* e = (Element*)item;
  if (!e) {
    g_print("e is NULL\n");
  }
  g_print("%s %u(%u)", (gchar*)prefix, e->data, e->priority);
}

/**
 * @brief Compare function for deciding where to the insert the new element
 *
 * @param a , node 1
 * @param b , node 2
 * @return gint, a>b = 1, a<b=-1 and a==b = 0
 */
gint compare( gconstpointer a, gconstpointer b) {
  Element *e1 = (Element *) a;
  Element *e2 = (Element *) b;
  guint p1 = e1->priority;
  guint p2 = e2->priority;

  if (p1 > p2) {
    return -1;
  } else if (p1 < p2) {
    return 1;
  }
  return 0;
}

/**
 * @brief pop top of the queue
 *
 * @param queue, queue pointer
 * @return Element*, popped node
 */
Element* pop(GList **queue) {
    GList *q = *queue;
    Element* e1 = NULL;
    if (q)
    {
      e1 = (Element *)(g_list_first(q)->data);
      q = g_list_remove(q, (gconstpointer)e1);
    }
    *queue = q;
    return e1;
}

/**
 * @brief Push element in the queue as per priority
 *
 * @param queue, pointer to the queue
 * @param e, new element to be inserted
 */
void push (GList **queue, Element* e) {
  *queue = g_list_prepend(*queue, (gpointer)e);
  *queue = g_list_sort(*queue, (GCompareFunc)compare);
}

/**
 * @brief peek the least priority element
 *
 * @param queue, pointer to the queue
 * @return Element*, pointer to the last element
 */
Element* peek(GList *queue) {
  return (Element *) (g_list_last(queue)->data);
}

/**
 * @brief check the top of the queue
 *
 * @param queue , pointer to the queue
 * @return Element*, pointer to the top of the queue
 */
Element* top(GList* queue) {
  return (Element *) (g_list_first(queue)->data);
}

/**
 * @brief Creates a new element
 *
 * @param data, value to be inserted
 * @param priority , priority
 * @return Element* , pointer to the newly created element
 */
Element *new_element(guint data, guint priority) {
  Element *e = g_new0(Element, 1);
  e->data = data;
  e->priority = priority;
  return e;
}

/**
 * @brief Free memory associated with the element
 *
 * @param item , pointer to the element
 */
void free_element(gpointer item) {
    Element* e = (Element*)item;
    if (e) {
        g_free(e);
    }
}

int main(int argc, char const *argv[])
{
  GList *p_queue = NULL;
  Element *e1 = new_element(5, 3);
  push(&p_queue, e1);
  g_list_foreach(p_queue, (GFunc)print_iterator, "list:");
  g_print("\n");
  Element *e2 = new_element(3, 1);
  push(&p_queue, e2);
  g_list_foreach(p_queue, (GFunc)print_iterator, "->");
  g_print("\n");
  Element* e3 = new_element(9, 5);
  push(&p_queue, e3);
  g_list_foreach(p_queue, (GFunc)print_iterator, "->");
  g_print("\n");

  e1 = peek(p_queue);
  print_iterator((gpointer)e1, "last element:");
  g_print("\n");

  e1 = top(p_queue);
  print_iterator((gpointer)e1, "first element:");
  g_print("\n");

  e1 = pop(&p_queue);
  g_print("Popped: %u(%u)\n", e1->data, e1->priority);
  free_element((gpointer)e1);
  g_print("after pop: ");
  g_list_foreach(p_queue, (GFunc)print_iterator, "->");
  g_print("\n");

  g_print("Freeing all elements of the list");
  g_list_foreach(p_queue, (GFunc)free_element, NULL);
  g_print("\n");
  return 0;
}
