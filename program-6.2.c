// Program 6.2
// Selection sort

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

void selection(Item a[], int l, int r) {
    int i, j, min;
    for (i = l; i < r; i++) {
        min = i;
        for (j = i + 1; j <= r; j++)
            if (less(a[j], a[min]))
                min = j;
        exch(a[min], a[i]);
    }
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    int *a = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    selection(a, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);

    return 0;
}
