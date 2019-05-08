#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../item_int.h"

#define MAX 1000 // range of item: [0,1000)
#define BASE 10  // decimal

#define LEN 10
int Input[LEN];

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
        for (int i = 1; i < BASE; i++)
            Cnt[i] += Cnt[i - 1];
        for (int i = 0; i < N; i++)
            B[Cnt[(A[i] / exp) % BASE]++] = A[i];
        for (int i = 0; i < N; i++)
            A[i] = B[i];
    }
}

int main(int argc, char *argv[]) {
    srand(time(0));
    randinit2(Input, LEN, rand_int);
    print(Input, LEN);
    radix_sort_lsd(Input, LEN);
    print(Input, LEN);
    return 0;
}
