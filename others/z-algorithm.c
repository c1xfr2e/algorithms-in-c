// Z-algorithm substring searching

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void native_z(char *s, int Z[], int N) {
    int i, z;
    Z[0] = N;
    for (i = 1; i < N; i++) {
        z = 0;
        while (i + z < N && s[z] == s[i + z])
            z++;
        Z[i] = z;
    }
}

void advanced_z(char *s, int Z[], int N) {
    int lt = 0, rt = 0, i, k, p, z, n;
    Z[0] = N;
    for (k = 1; k < N; k++) {
        if (k > rt) { // naive, brute force
            n = 0;
            while (k + n < N && s[k + n] == s[n])
                n++;
            Z[k] = n;
            if (n > 0) {
                lt = k;
                rt = k + n - 1;
            }
        } else {
            Z[k] = -1;
        }
    }
}

bool test_z(int a[], int b[], int N) {
    int i;
    for (i = 0; i < N && a[i] == b[i]; i++)
        ;
    return i == N;
}

int main(int argc, char *argv[]) {
    int N = strlen(argv[1]);
    int *Z = malloc(N * sizeof *Z);
    advanced_z(argv[1], Z, N);
    for (int i = 0; i < N; i++)
        printf("%d ", Z[i]);
    return 0;
}
