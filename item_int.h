#ifndef ITEM_INT_H
#define ITEM_INT_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

static inline Item ITEMrand() {
    return rand() % 100;
}

static inline void randinit(Item a[], int N) {
    for (int i = 0; i < N; i++)
        a[i] = ITEMrand();
}

static inline void print(Item a[], int N) {
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

#endif
