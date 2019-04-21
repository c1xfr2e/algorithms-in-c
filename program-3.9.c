// Program 3.9
// Circular list Josephus problem

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"
#include "list_node.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("not enough arguments\n");
        exit(-1);
    }
    int N = atoi(argv[1]), M = atoi(argv[2]);
    printf("N=%d M=%d\n", N, M);
    link t = malloc(sizeof *t), x = t;
    t->item = 1;
    t->next = t;
    for (int i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = i;
        x->next = t;
    }
    while (x->next != x) {
        for (int i = 1; i < M; i++) {
            x = x->next;
        }
        printf("remove: %d\n", x->next->item);
        x->next = x->next->next;
    }
    printf("last: %d\n", x->item);
    return 0;
}
