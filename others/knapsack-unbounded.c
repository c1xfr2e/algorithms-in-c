// unbounded knapsack problem
// 5 17
// 4  5  10 11 13
// 3  4  7  8  9

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int N, W;
int Vx[20], Wx[20];

int knapsack(int w) {
    int i, v, max = 0;
    for (i = 0; i < N; i++)
        if (w - Wx[i] >= 0)
            if ((v = Vx[i] + knapsack(w - Wx[i])) > max)
                max = v;
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
    printf("input Wx: \n");
    for (i = 0; i < N; i++) {
        scanf("%d", &w);
        Wx[i] = w;
    }
    printf("Vx: ");
    for (int i = 0; i < N; i++)
        printf("%3d ", Vx[i]);
    printf("\n");
    printf("Wx: ");
    for (int i = 0; i < N; i++)
        printf("%3d ", Wx[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    read();
    printf("Max: %3d\n", knapsack(W));
}
