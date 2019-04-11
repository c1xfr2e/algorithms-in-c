
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../item_int.h"

struct node {
    Item item;
    struct node *l;
    struct node *r;
};

typedef struct node *link;

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

int main(int argc, char *argv[]) {
    char *s = "ab#c##de###"; // argv[1];
    link x = build_tree(&s);
    traverse(x, print_item);
    return 0;
}
