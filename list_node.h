#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "item_int.h"

typedef struct node *link;
struct node {
    Item item;
    link next;
};

#endif
