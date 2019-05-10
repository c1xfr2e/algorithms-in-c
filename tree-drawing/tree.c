
#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
    int Item;
    link L, R;
    int H;
    float root_pos;
};

#define NEW_NODE(i)                 \
    ({                              \
        link t = malloc(sizeof *t); \
        t->Item = i;                \
        t->L = t->R = NULL;         \
        t->H = 0;                   \
        t->root_pos = 0.0f;         \
        t;                          \
    })

int traverse_to_calc_height(link t) {
    if (t == NULL)
        return 0;
    int lh = traverse_to_calc_height(t->L);
    int rh = traverse_to_calc_height(t->R);
    t->H = lh > rh ? lh + 1 : rh + 1;
    return t->H;
}

int main(int argc, char *argv[]) {
    link tree = NEW_NODE(1);
    link l = NEW_NODE(2);
    link l1 = NEW_NODE(3);
    link l2 = NEW_NODE(4);
    link r = NEW_NODE(5);
    link r2 = NEW_NODE(6);
    tree->L = l;
    tree->R = r;
    l->L = l1;
    l->R = l2;
    r->R = r2;
    r2->R = NEW_NODE(7);
    traverse_to_calc_height(tree);
    return 0;
}