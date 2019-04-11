
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../item_int.h"

typedef struct node *link;
struct node {
    Item item;
    struct node *l;
    struct node *r;
};

#define NEW_NODE(i)                 \
    ({                              \
        link t = malloc(sizeof *t); \
        t->item = i;                \
        t->l = t->r = NULL;         \
        t;                          \
    })

#define foo(x)                                  \
    ({                                          \
        int xx = (x);                           \
        int result = (xx > 32) ? xx : (2 * xx); \
        result;                                 \
    })

link build_tree(char **ps) {
    char c = **ps;
    (*ps)++;
    if (c == '#' || c == '\0')
        return NULL;
    link x = malloc(sizeof *x);
    x->item = c;
    x->l = build_tree(ps);
    // (*ps)++;
    x->r = build_tree(ps);
    // (*ps)++;
    return x;
}

void print_item(Item item) {
    printf("%c ", item);
}

void traverse(link x, void (*visit)(Item)) {
    if (x == NULL)
        return;
    visit(x->item);
    traverse(x->l, visit);
    traverse(x->r, visit);
}

#define STACK_MAX 100
link stack[STACK_MAX];
int top = STACK_MAX;

link pop() {
    return stack[top++];
}

void push(link x) {
    stack[--top] = x;
}

void try_stack() {
    push(NEW_NODE(1));
    push(NEW_NODE(2));
    push(NEW_NODE(3));
    printf("%d ", pop()->item);
    printf("%d ", pop()->item);
    push(NEW_NODE(4));
    push(NEW_NODE(5));
    printf("%d ", pop()->item);
    push(NEW_NODE(6));
    printf("%d ", pop()->item);
    printf("%d ", pop()->item);
    printf("%d \n", pop()->item);
}

int main(int argc, char *argv[]) {
    try_stack();
    char *s = "ab#c##de###"; // argv[1];
    link x = build_tree(&s);
    traverse(x, print_item);
    return 0;
}
