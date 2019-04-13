// gcc tree-traverse.c
// ./a.out abc##d##ef##g##

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../item_int.h"

enum NodeType {
    kNode = 0,
    kItem = 1,
};

typedef struct node *link;
struct node {
    Item item;
    struct node *l;
    struct node *r;
    enum NodeType type; // for postorder traverse
};

#define NEW_NODE(i)                 \
    ({                              \
        link t = malloc(sizeof *t); \
        t->item = i;                \
        t->l = t->r = NULL;         \
        t;                          \
    })

#define NODE(n)          \
    ({                   \
        n->type = kNode; \
        n;               \
    })

#define ITEM(n)          \
    ({                   \
        n->type = kItem; \
        n;               \
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

void stack_init() {
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
    stack_init();
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

void traverse_in_nr(link tree, void (*visit)(Item)) {
    stack_init();
    link x = tree;
    while (x) {
        stack_push(x);
        x = x->l;
    }
    while (!stack_empty()) {
        x = stack_pop();
        visit(x->item);
        x = x->r;
        while (x) {
            stack_push(x);
            x = x->l;
        }
    }
}

void traverse_post(link x, void (*visit)(Item)) {
    if (x == NULL)
        return;
    traverse_post(x->l, visit);
    traverse_post(x->r, visit);
    visit(x->item);
}

void traverse_post_nr(link tree, void (*visit)(Item)) {
    stack_init();
    link x = tree;
    stack_push(NODE(x));
    while (!stack_empty()) {
        x = stack_pop();
        if (x->type == kNode) {
            stack_push(ITEM(x));
            if (x->r)
                stack_push(NODE(x->r));
            if (x->l)
                stack_push(NODE(x->l));
        } else {
            visit(x->item);
        }
    }
}

void print_item(Item item) {
    printf("%c ", item);
}

int main(int argc, char *argv[]) {
    // try_stack();
    char *s = argv[1];
    link x = build_tree(&s);
    printf("preorder\n\t");
    traverse_pre(x, print_item);
    printf("\n\t");
    traverse_pre_nr(x, print_item);
    printf("\n");
    printf("inorder\n\t");
    traverse_in(x, print_item);
    printf("\n\t");
    traverse_in_nr(x, print_item);
    printf("\n");
    printf("postorder\n\t");
    traverse_post(x, print_item);
    printf("\n\t");
    traverse_post_nr(x, print_item);

    return 0;
}
