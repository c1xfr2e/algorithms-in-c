// 0-1 knapsack problem
// 4 10
// 10 40 30 50
// 5  4  6  3

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int N, W;
int Vx[20], Wx[20];
int F[20];

int knapsack(int k, int w) {
    int i, j, v, max = 0;
    F[k] = -1;
    for (i = 0; i <= k; i++) {
        if (Wx[i] <= w) {
            v = Vx[i] + knapsack(i - 1, w - Wx[i]);
            j = i;
        } else {
            v = knapsack(i - 1, w);
            j = -1;
        }
        if (v > max) {
            max = v;
            F[k] = j;
        }
    }
    return max;
}

void read() {
    int i, v, w;
    printf("input N and W: \n");
    scanf("%d %d", &N, &W);
    printf("input Vx: \n");
    for (i = 0; i < N; i++) {
        scanf("%d", &v);
        Vx[i] = v;
    }
    printf("input W: \n");
    for (i = 0; i < N; i++) {
        scanf("%d", &w);
        Wx[i] = w;
    }
    printf("V: ");
    for (int i = 0; i < N; i++)
        printf("%3d ", Vx[i]);
    printf("\n");
    printf("Wx: ");
    for (int i = 0; i < N; i++)
        printf("%3d ", Wx[i]);
    printf("\n");
}

void print() {
}

int main(int argc, char *argv[]) {
    read();
    printf("Max: %3d\n", knapsack(N - 1, W));
    printf("F: ");
    for (int i = 0; i < N; i++)
        printf("%3d ", F[i]);
    return 0;
}
