// input: 0 6  0 1  0 2  0 5  4 7  0 7  2 7  1 7  3 4  3 5  4 5  4 6 $

#include <stdbool.h>
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

#define V 8
#define STACK_MAX 100

int stack[STACK_MAX];
int top = STACK_MAX;
int stack_pop() { return stack[top++]; }
void stack_push(int i) { stack[--top] = i; }
bool stack_empty() { return top == STACK_MAX; }
void stack_init() { top = STACK_MAX; }

link adj[V];
bool visited[V];

void dfs_nr(int v, void (*visit)(int)) {
    stack_init();
    stack_push(v);
    int x;
    link k;
    while (!stack_empty()) {
        x = stack_pop();
        if (visited[x])
            continue;
        visit(x);
        visited[x] = true;
        for (k = adj[x]; k; k = k->next)
            stack_push(k->v);
    }
}

void print_adj() {
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

void print_int(int v) {
    printf("%d ", v);
}

int main(int argc, char *argv[]) {
    int i, j;
    for (i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }
    while (scanf("%d %d", &i, &j) == 2) {
        adj[j] = NEW(i, adj[j]);
        adj[i] = NEW(j, adj[i]);
    }

    print_adj();
    dfs_nr(0, print_int);

    return 0;
}
