// Reverse a linked list recursively
//
// gcc -o program-3.10 program-3.10.c exercise-5.15.c

#include <stdio.h>

#include "list_node.h"

static link tail;

link reverse_r(link x) {
    if (x->next == NULL) {
        tail = x;
        return x;
    }
    link y = reverse_r(x->next);
    tail->next = x;
    x->next = NULL;
    tail = x;
    return y;
}
