// Program 3.19
// Adjacency-lists graph representation
// ./a.out
//  0 6  0 1  0 2  0 5  4 7  0 7  2 7  1 7  3 4  3 5  4 5  4 6 $

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int v;
    link next;
};

link NEW(int v, link next) {
    link x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}

#define V 10

void print_adj(link adj[]) {
    for (int i = 0; i < V; i++) {
        link x = adj[i];
        if (!x)
            continue;
        printf("%d: ", i);
        while (x) {
            printf("%d ", x->v);
            x = x->next;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    link adj[V];
    for (i = 0; i < V; i++)
        adj[i] = NULL;
    while (scanf("%d %d", &i, &j) == 2) {
        adj[j] = NEW(i, adj[j]);
        adj[i] = NEW(j, adj[i]);
    }

    print_adj(adj);

    return 0;
}
