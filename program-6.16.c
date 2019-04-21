// Program 6.15
// Linked-list selection sort

#include "item_int.h"
#include "program-6.15.h"

#include <stdio.h>
#include <stdlib.h>

link listselection(link h) {
    link max, t, out = NULL;
    while (h->next != NULL) {
        max = find_max(h);
        t = max->next;
        max->next = t->next;
        t->next = out;
        out = t;
    }
    return out;
}

int main(int argc, char *argv[]) {
    show(listselection(init(atoi(argv[1]))));
    return 0;
}
