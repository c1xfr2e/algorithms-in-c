
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

bool verify_partition(int a[], int n, int p, int v) {
    if (a[p] != v)
        return false;
    for (int i = 0; i < p; i++)
        if (a[i] > v)
            return false;
    for (int i = p + 1; i < n; i++)
        if (a[i] < v)
            return false;
    return true;
}

int partition(int a[], int l, int r) {
    int i = l - 1, j = r, v = a[r];
    while (true) {
        while (a[++i] < v)
            ;
        while (a[--j] > v)
            if (j == l)
                break;
        if (i >= j)
            break;
        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

int main(int argc, char *argv[]) {
    int N = 10;
    int a[] = {2, 4, 0, 8, 1, 3, 6, 9, 7, 5};
    int i = partition(a, 0, N - 1);
    if (!verify_partition(a, N, i, a[i])) {
        printf("verify partition failed");
        return 1;
    }
    for (int j = 0; j < N; j++) {
        if (j == i)
            printf("*%d* ", a[i]);
        else
            printf("%d ", a[j]);
    }
    return 0;
}
