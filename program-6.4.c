// Program 6.4
// Bubble sort
// ./a.out 2 1 4 7 3 6 5 8 0 9

#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"

#define less(a, b) ((a) < (b))

#define exch(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }

void bubble(Item a[], int l, int r) {
    int i, j;
    for (i = l; i < r; i++)
        for (j = r; j > i; j--)
            if (less(a[j], a[j - 1]))
                exch(a[j], a[j - 1]);
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    int *a = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    bubble(a, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);

    return 0;
}
