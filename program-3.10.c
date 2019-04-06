// Program 3.10
// Build a linked list from input integers and reverse it.

#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

link reverse(link x) {
    link r = NULL, y = x, next;
    while (y) {
        next = y->next;
        y->next = r;
        r = y;
        y = next;
    }
    return r;
}

link reverse_r(link x);

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    link h = malloc(sizeof *h), x = h;
    h->item = atoi(argv[2]);
    h->next = NULL;
    for (int i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = atoi(argv[i + 1]);
        x->next = NULL;
    }

    h = reverse(h);
    for (link l = h; l != NULL; l = l->next) {
        printf("%d ", l->item);
    }
    printf("\n");
    h = reverse_r(h);
    for (link l = h; l != NULL; l = l->next) {
        printf("%d ", l->item);
    }

    return 0;
}
