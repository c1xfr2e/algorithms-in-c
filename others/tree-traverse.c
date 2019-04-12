
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

#define STACK_MAX 100
link stack[STACK_MAX];
int top = STACK_MAX;

link stack_pop() {
    return stack[top++];
}

void stack_push(link x) {
    stack[--top] = x;
}

bool stack_empty() {
    return top == STACK_MAX;
}

void stack_clear() {
    top = STACK_MAX;
}

void try_stack() {
    top = STACK_MAX;
    stack_push(NEW_NODE(1));
    stack_push(NEW_NODE(2));
    stack_push(NEW_NODE(3));
    printf("%d ", stack_pop()->item);
    printf("%d ", stack_pop()->item);
    stack_push(NEW_NODE(4));
    stack_push(NEW_NODE(5));
    printf("%d ", stack_pop()->item);
    stack_push(NEW_NODE(6));
    printf("%d ", stack_pop()->item);
    printf("%d ", stack_pop()->item);
    printf("%d \n", stack_pop()->item);
}

link build_tree(char **ps) {
    char c = **ps;
    (*ps)++;
    if (c == '#' || c == '\0')
        return NULL;
    link x = malloc(sizeof *x);
    x->item = c;
    x->l = build_tree(ps);
    x->r = build_tree(ps);
    return x;
}

void traverse_pre(link x, void (*visit)(Item)) {
    if (x == NULL)
        return;
    visit(x->item);
    traverse_pre(x->l, visit);
    traverse_pre(x->r, visit);
}

// Traverse tree in preorder non-recursively.
void traverse_pre_nr(link tree, void (*visit)(Item)) {
    stack_clear();
    link x = tree;
    while (true) {
        if (!x) {
            if (stack_empty())
                break;
            x = stack_pop();
        }
        visit(x->item);
        if (x->r)
            stack_push(x->r);
        x = x->l;
    }
}

void traverse_in(link x, void (*visit)(Item)) {
    if (x == NULL)
        return;
    traverse_in(x->l, visit);
    visit(x->item);
    traverse_in(x->r, visit);
}

void print_item(Item item) {
    printf("%c ", item);
}

int main(int argc, char *argv[]) {
    // try_stack();
    char *s = argv[1];
    link x = build_tree(&s);
    traverse_pre(x, print_item);
    printf("\n");
    traverse_pre_nr(x, print_item);
    printf("\n");
    traverse_in(x, print_item);
    printf("\n");

    return 0;
}
