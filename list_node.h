#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef int Item;
typedef struct node *link;
struct node {
  Item item;
  link next;
};

#endif
