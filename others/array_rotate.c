// Array rotate

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

typedef char Item;

void rotate_cycle(Item A[], int L, int M, int R) {
    int d = M - L, n = R - L + 1;
    int g = gcd(n, d);
    while (g--) {
        int initial = L + g;
        Item tmp = A[initial];
        int p = initial, q = initial + d;
        while (q != initial) {
            A[p] = A[q];
            p = q;
            q = L + (q + d - L) % n;
        }
        A[p] = tmp;
    }
}

void reverse(Item A[], int L, int R) {
    while (L < R) {
        Item tmp = A[L];
        A[L] = A[R];
        A[R] = tmp;
        L++;
        R--;
    }
}

void rotate_by_reverse(Item A[], int L, int M, int R) {
    if (M - L <= 0 || R - M < 0)
        return;
    reverse(A, L, M - 1);
    reverse(A, M, R);
    reverse(A, L, R);
}

int main(int argc, char *argv[]) {
    char s[] = "--ABCDEFGHIJ--";
    for (int i = 0; i < strlen(s); i++)
        printf("%2d ", i);
    printf("\n");
    for (int i = 0; i < strlen(s); i++)
        printf("%2c ", s[i]);
    printf("\n");
    rotate_by_reverse(s, 2, 5, 11);
    for (int i = 0; i < strlen(s); i++)
        printf("%2c ", s[i]);
    return 0;
}
