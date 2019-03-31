
#include <stdio.h>
#include <stdlib.h>

#define LEFT(N) (N * 2 + 1)
#define RIGHT(N) (N * 2 + 2)
#define PARENT(N) ((N - 1) / 2)

typedef int Item;

void sift_down(Item *heap, int start, int top) {
    Item item = heap[start];
    int x = start, y;
    while (x > top) {
        y = PARENT(x);
        if (item < heap[y]) {
            heap[x] = heap[y];
            x = y;
            continue;
        }
        break;
    }
    heap[x] = item;
}

void sift_up(Item *heap, int start, int N) {
    int x = start, child = LEFT(start), right;
    Item item = heap[start];
    while (child < N) {
        right = child + 1;
        if (right < N && heap[right] < heap[child])
            child = right;
        heap[x] = heap[child];
        x = child;
        child = LEFT(x);
    }
    heap[x] = item;
    sift_down(heap, x, start);
}

int main(int argc, char *argv[]) {
    int N = argc - 1;
    Item *heap = malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++)
        heap[i] = atoi(argv[i + 1]);
    for (int i = N / 2 - 1; i >= 0; i--)
        sift_up(heap, i, N);
    for (int i = 0; i < N; i++)
        printf("%d ", heap[i]);
    return 0;
}
