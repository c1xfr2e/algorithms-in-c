// Exercise 6.64
// Implementation of linked-list-type interface in Program 6.15

#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"
#include "program-6.15.h"

link NEW(Item item, link next) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

link init(int N) {
    link h = malloc(sizeof *h), x = h;
    h->next = NULL;
    for (int i = 0; i < N; i++) {
        x = (x->next = malloc(sizeof *x));
        scanf("%d", &x->item);
        x->next = NULL;
    }
    return h;
}

void show(link h) {
    while (h) {
        printf("%d ", h->item);
        h = h->next;
    }
}

link find_max(link h) {
    Item max = INT32_MIN;
    link x = h;
    while (h->next) {
        if (h->next->item > max) {
            x = h;
            max = h->next->item;
        }
        h = h->next;
    }
    return x;
}
