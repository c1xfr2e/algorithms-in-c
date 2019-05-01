// Program 8.4
// Mergesort with no copying
// gcc -std=c11 program-8.4.c program-8.1.c program-6.3.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item_int.h"

void mergeAB(Item c[], Item a[], int N, Item b[], int M);
void insertion(Item a[], int l, int r);

// Sort b, leaving result in a.
void mergesortABr(Item a[], Item b[], int l, int r) {
    int m = (l + r) / 2;
    if (r - l <= 10) {
        insertion(a, l, r);
        return;
    }
    mergesortABr(b, a, l, m);
    mergesortABr(b, a, m + 1, r);
    mergeAB(a + l, b + l, m - l + 1, b + m + 1, r - m);
}

#define maxN 100
Item aux[maxN];

void mergesortAB(Item a[], int l, int r) {
    int i;
    for (i = l; i <= r; i++)
        aux[i] = a[i];
    mergesortABr(a, aux, l, r);
}

int A[20];

int main(int argc, char *argv[]) {
    srand(time(0));
    randinit(A, 20);
    print(A, 20);
    mergesortAB(A, 0, 19);
    print(A, 20);
}
