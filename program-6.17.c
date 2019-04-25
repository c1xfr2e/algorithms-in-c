// Program 6.17
// Key-indexed counting
// ./a.out 28 6 33 2 77 4 15 34 347 112

#include <stdio.h>
#include <stdlib.h>

#define M 1000 // range of item: [0,1000)
#define maxN 100

void distcount(int a[], int l, int r) {
    int i, j, cnt[M];
    int b[maxN];
    for (i = 0; i < M; i++)
        cnt[i] = 0;
    for (i = l; i <= r; i++)
        cnt[a[i] + 1]++;
    for (j = 1; j < M; j++)
        cnt[j] += cnt[j - 1];
    for (i = l; i <= r; i++)
        b[cnt[a[i]]++] = a[i];
    for (i = l; i <= r; i++)
        a[i] = b[i - l];
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    int *a = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 1]);
    }
    distcount(a, 0, N - 1);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    return 0;
}
