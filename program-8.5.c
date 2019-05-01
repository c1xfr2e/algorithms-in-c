// Program 8.5
// Bottom-up mergesort
// gcc -std=c11 program-8.5.c program-8.2.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item_int.h"

#define min(A, B) (A < B) ? A : B

void merge(Item a[], int l, int m, int r);

void mergesortBU(Item a[], int l, int r) {
    int i, m;
    for (m = 1; m <= r - l; m = m + m)
        for (i = l; i <= r - m; i += m + m)
            merge(a, i, i + m - 1, min(i + m + m - 1, r));
}

#define N 16
int A[N];

int main(int argc, char *argv[]) {
    srand(time(0));
    randinit(A, N);
    print(A, N);
    mergesortBU(A, 0, N - 1);
    print(A, N);
    return 0;
}
