// Program 3.11
// List insertion sort

#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    struct node heada, headb;
    heada.next = headb.next = NULL;
    srand(time(0));
    link t = &heada;
    for (int i = 0; i < N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 100;
    }
    link n, b;
    for (link a = heada.next; a != NULL; a = n) {
        n = a->next;
        for (b = &headb; b->next != NULL; b = b->next) {
            if (b->next->item > a->item) {
                break;
            }
        }
        a->next = b->next;
        b->next = a;
    }
    for (link x = headb.next; x != NULL; x = x->next) {
        printf("%d ", x->item);
    }
    return 0;
}
