// Program 4.4
// Array implementation of a pushdown stack

#include <stdlib.h>

#include "item_int.h"
#include "STACK.h"

static Item *s;
static int N;

void STACKinit(int maxN) {
    s = malloc(maxN * sizeof(Item));
    N = 0;
}

int STACKempty() {
    return N == 0;
}

void STACKpush(Item item) {
    s[N++] = item;
}

Item STACKpop() {
    return s[--N];
}
