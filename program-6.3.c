// Program 6.2
// Insertion sort
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

void insertion(Item a[], int l, int r) {
    for (int i = r; i > l; i--)
        if (less(a[i], a[i - 1]))
            exch(a[i], a[i - 1]);
    for (int i = l + 2; i <= r; i++) {
        int j = i - 1;
        Item v = a[i];
        while (less(v, a[j])) {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = v;
    }
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    int *a = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    insertion(a, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);

    return 0;
}
