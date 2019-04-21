// Program 6.15
// Linked-list-type interface definition

#ifndef PROGRAM_6_15_H
#define PROGRAM_6_15_H

typedef struct node *link;

struct node {
    Item item;
    link next;
};

link NEW(Item, link);
link init(int);
void show(link);
link sort(link);

link find_max(link);

#endif
