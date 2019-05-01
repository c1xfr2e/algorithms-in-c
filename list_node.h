#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node *link;
struct node {
    Item item;
    link next;
};

static inline link randlist(int N) {
    srand(time(0));
    link head = malloc(sizeof *head);
    link t = head;
    for (int i = 0; i < N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 100;
    }
    return head;
}

static inline void printlist(link h) {
    for (link x = h; x != NULL; x = x->next) {
        printf("%d ", x->item);
    }
    printf("\n");
}

#endif
