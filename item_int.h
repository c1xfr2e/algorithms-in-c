#ifndef ITEM_INT_H
#define ITEM_INT_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(a, b) ((a) < (b))

#define exch(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }

static inline Item ITEMrand() {
    return rand() % 100;
}

static inline void randinit(Item a[], int N) {
    for (int i = 0; i < N; i++)
        a[i] = ITEMrand();
}

static inline void randinit2(Item a[], int N, int (*r)()) {
    for (int i = 0; i < N; i++)
        a[i] = r();
}

static inline void print(Item a[], int N) {
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

static inline void printlr(Item a[], int l, int r) {
    for (int i = l; i <= r; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

#endif
