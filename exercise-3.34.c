// Exercise 3.34
// Move the largest item on a list to the final node.

#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    link head = malloc(sizeof *head), last = head;
    for (int i = 0; i < N; i++) {
        last = (last->next = malloc(sizeof *last));
        last->item = atoi(argv[i + 2]);
        last->next = NULL;
    }

    int max = head->next->item;
    link x = head;
    for (link n = head->next; n->next != NULL; n = n->next) {
        if (n->next->item > max) {
            max = n->next->item;
            x = n;
        }
    }

    last->next = x->next;
    last = x->next;
    x->next = x->next->next;
    last->next = NULL;

    for (link n = head->next; n != NULL; n = n->next) {
        printf("%d ", n->item);
    }

    return 0;
}
