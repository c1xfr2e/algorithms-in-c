// Exercise 3.36
// Rearrange a list to put the nodes in even positions after the nodes in odd
// positions.

#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"
#include "list_node.h"

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    struct node head;
    link t = &head;
    for (int i = 0; i < N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->item = atoi(argv[i + 2]);
        t->next = NULL;
    }
    link x = head.next, y = x->next->next, z, w, u = x->next;
    while (y) {
        z = y->next ? y->next->next : NULL;
        w = x->next;
        x->next = y;
        u->next = y->next;
        u = y->next;
        y->next = w;
        x = y;
        y = z;
    }
    for (t = head.next; t != NULL; t = t->next) {
        printf("%d ", t->item);
    }
    return 0;
}
