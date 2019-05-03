// Program 1

#include <stdio.h>
#include <stdlib.h>

#include "../item_int.h"
#include "../list_node.h"

typedef struct {
    link pivot, left, left_tail, right;
} cut;

void print_cut(cut c) {
    for (link i = c.left; i != NULL; i = i->next)
        printf("%4d", i->item);
    printf("%3d*", c.pivot->item);
    for (link i = c.right; i != NULL; i = i->next)
        printf("%4d", i->item);
    printf("\n");
}

cut partition(link x) {
    cut c;
    c.left = c.left_tail = c.right = NULL;
    c.pivot = x;
    Item v = x->item;
    x = x->next;
    while (x) {
        link y = x->next;
        if (x->item <= v) {
            x->next = c.left;
            c.left = x;
            if (c.left_tail == NULL)
                c.left_tail = x;
        } else {
            x->next = c.right;
            c.right = x;
        }
        x = y;
    }
    if (c.left_tail != NULL) {
        c.left_tail->next = NULL;
    }
    c.pivot->next = NULL;
    return c;
}

typedef struct {
    link first, last;
} subfile;

subfile new_subfile(link fi, link la) {
    subfile r = {fi, la};
    return r;
}

subfile quicksort(link x) {
    if (x == NULL || x->next == NULL) {
        return new_subfile(x, x);
    }
    cut c = partition(x);
    print_cut(c);
    subfile sub1 = quicksort(c.left);
    subfile sub2 = quicksort(c.right);
    c.pivot->next = sub2.first;
    if (sub1.first == NULL)
        return new_subfile(c.pivot, sub2.last);
    sub1.last->next = c.pivot;
    link last = (sub2.last != NULL) ? sub2.last : c.pivot;
    return new_subfile(sub1.first, last);
}

int main(int argc, char *argv[]) {
    subfile all = quicksort(randlist(10));
    printlist(all.first);
    return 0;
}
