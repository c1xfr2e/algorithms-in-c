#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef struct node *link;
struct node {
    Item item;
    link next;
};

#endif
