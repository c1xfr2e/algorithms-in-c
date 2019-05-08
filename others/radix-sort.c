// 小时候家里很穷，家里最值钱的就是挂在大门上的一把铁锁，今天下大雨了，我就跑在
// 铁锁面前抱着它哭了着说：老铁，求求你了，别绣了，别绣了

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../item_int.h"

#define MAX 1000 // range of item: [0,1000)
#define BASE 10  // decimal

#define LEN 15
int Input[LEN];
int Input2[LEN];

int rand_int() {
    return rand() % MAX;
}

void radix_sort_lsd(int A[], int N) {
    int B[N];
    int Cnt[BASE + 1];
    for (int exp = 1; exp < MAX; exp *= BASE) {
        for (int i = 0; i <= BASE; i++)
            Cnt[i] = 0;
        for (int i = 0; i < N; i++) {
            int p = (A[i] / exp) % BASE;
            Cnt[p + 1] += 1;
        }
        for (int i = 1; i <= BASE; i++)
            Cnt[i] += Cnt[i - 1];
        for (int i = 0; i < N; i++)
            B[Cnt[(A[i] / exp) % BASE]++] = A[i];
        for (int i = 0; i < N; i++)
            A[i] = B[i];
    }
}

void radix_sort_msd(int A[], int l, int r, int exp) {
    if (r < l || exp == 0)
        return;
    int B[r - l + 1];
    int Cnt[BASE + 1];
    for (int i = 0; i <= BASE; i++)
        Cnt[i] = 0;
    for (int i = l; i <= r; i++) {
        int p = (A[i] / exp) % BASE;
        Cnt[p + 1] += 1;
    }
    for (int i = 1; i <= BASE; i++)
        Cnt[i] += Cnt[i - 1];
    for (int i = l; i <= r; i++)
        B[Cnt[(A[i] / exp) % BASE]++] = A[i];
    for (int i = l; i <= r; i++)
        A[i] = B[i - l];
    for (int i = 0, j = 0; j < BASE; j++) {
        radix_sort_msd(A, i, Cnt[j] - 1, exp / BASE);
        i = Cnt[j];
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));

    randinit2(Input, LEN, rand_int);
    print(Input, LEN);
    radix_sort_msd(Input, 0, LEN - 1, MAX);
    print(Input, LEN);

    randinit2(Input2, LEN, rand_int);
    radix_sort_lsd(Input2, LEN);
    print(Input2, LEN);

    return 0;
}
