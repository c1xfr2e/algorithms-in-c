
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define exch(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void print(int A[], int N) {
    int i;
    for (i = 0; i < N; i++)
        printf("%2d ", i);
    printf("\n");
    for (i = 0; i < N; i++)
        printf("%2d ", A[i]);
    printf("\n");
}

void reverse(int A[], int L, int R) {
    while (L < R) {
        exch(A[L], A[R]);
        L++;
        R--;
    }
}

void rotate(int A[], int L, int M, int R) {
    if (M - L <= 0 || R - M < 0)
        return;
    reverse(A, L, M - 1);
    reverse(A, M, R);
    reverse(A, L, R);
}

int lower_bound(int A[], int v, int L, int R) {
    while (L <= R) {
        int m = (L + R) / 2;
        if (A[m] < v) {
            L = m + 1;
        } else {
            R = m;
            if (R == L) // prevent infinite loop
                break;
        }
    }
    return L;
}

// merge sorted sub-array A[L,M-1] and A[M,R]
void in_place_merge(int A[], int L, int M, int R) {
    if (M <= L || M > R)
        return;
    if (R - L == 1) {
        if (A[R] < A[L])
            exch(A[L], A[R]);
    }
    int p = (L + M - 1) / 2;
    int q = lower_bound(A, A[p], M, R);
    rotate(A, p, M, q - 1);
    int new_m = p + (q - M);
    in_place_merge(A, L, p, new_m - 1);
    if (new_m == p)
        in_place_merge(A, p + 1, q, R);
    else
        in_place_merge(A, new_m, q, R);
}

int input1[] = {3, 4, 5, 7, 9, 0, 1, 2, 6, 8};
int input2[] = {3, 4, 5, 6, 13, 14, 15, 0, 1, 2, 7, 8, 9, 10};

int main(int argc, char *argv[]) {
    in_place_merge(input1, 0, 5, 9);
    print(input1, 10);
    in_place_merge(input2, 0, 7, 13);
    print(input2, 14);
    return 0;
}
