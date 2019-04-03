// Program 4.19
// Queue client program (queue simulation)
//
// gcc -std=c11 -g program-4.19.c program-4.20.c -o program-4.19

#include <stdio.h>
#include <stdlib.h>

#include "item_int.h"
#include "QUEUE.h"

#define M 10

int main(int argc, char *argv[]) {
    int i, j, N = atoi(argv[1]);
    Q queues[M];
    for (i = 0; i < M; i++)
        queues[i] = QUEUEinit(N);
    for (j = 0; j < N; j++)
        QUEUEput(queues[rand() % M], j);
    for (i = 0; i < M; i++, printf("\n"))
        for (j = 0; !QUEUEempty(queues[i]); j++)
            printf("%d ", QUEUEget(queues[i]));
    return 0;
}
