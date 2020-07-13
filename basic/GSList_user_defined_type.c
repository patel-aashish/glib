#include <glib.h>
#include <gmodule.h>

typedef struct {
    char *name;
    int weight;
} Person;

int main(int argc, char **argv) {
    GSList *list = NULL;
    // Allocate memory for a object
    Person *tom = g_new(Person, 1);
    tom->name = "Tom";
    tom->weight = 75;
    list = g_slist_append(list, tom);
    Person *joe = g_new(Person, 1);
    joe->name = "Joe";
    joe->weight = 89;
    list = g_slist_append(list, joe);

    // Accessing elements of the list
    g_print("First person's name is %s\n", ((Person *)(list->data))->name);
    g_print("Last person's weight is %d\n", ((Person *)g_slist_last(list)->data)->weight);

    // Free allocated memory
    g_free(tom);
    g_free(joe);

    return 0;
}