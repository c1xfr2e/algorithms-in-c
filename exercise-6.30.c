// Exercise 6.30
// Shaker sort
// ./a.out 2 1 4 7 3 6 5 8 0 9

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"

void shaker(Item a[], int l, int r) {
    while (l < r) {
        for (int i = l; i < r; i++)
            if (less(a[i + 1], a[i])) {
                exch(a[i + 1], a[i]);
            }
        r--;
        for (int i = r; i > l; i--)
            if (less(a[i], a[i - 1])) {
                exch(a[i], a[i - 1]);
            }
        l++;
    }
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    int *a = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    shaker(a, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%2d ", a[i]);

    return 0;
}
