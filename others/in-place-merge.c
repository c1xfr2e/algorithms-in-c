
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void reverse(int A[], int L, int R) {
    while (L < R) {
        exch(A[L], A[R]);
        L++;
        R--;
    }
}

void rotate(int A[], int L, int M, int R) {
    reverse(A, L, M - 1);
    reverse(A, M, R);
    reverse(A, L, R);
}

// merge sorted sub-array A[L,M-1] and A[M,R]
void in_place_merge(int A[], int L, int M, int R) {
}

int main(int argc, char *argv[]) {
    int a[] = {3, 4, 5, 6, 13, 14, 15, 0, 1, 2, 7, 8, 9, 10};
    int N = 14, m = 7;
    in_place_merge(a, 0, m, N - 1);
    rotate(a, 0, 4, 6);
    for (int j = 0; j < N; j++) {
        printf("%d ", a[j]);
    }
    return 0;
}
