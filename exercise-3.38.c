// Exercise 3.38
// Copy list

#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

link copy_list(link head) {
  link h = malloc(sizeof *h), t = h;
  for (link x = head->next; x != NULL; x = x->next) {
    t->next = malloc(sizeof *t);
    t = t->next;
    t->item = x->item;
  }
  t->next = NULL;
  return h;
}

int main(int argc, char *argv[]) {
  struct node head;
  link t = &head;
  for (int i = 0; i < argc - 1; i++) {
    t->next = malloc(sizeof *t);
    t = t->next;
    t->item = atoi(argv[i + 1]);
    t->next = NULL;
  }
  link cpy = copy_list(&head);
  for (t = head.next; t != NULL; t = t->next) {
    printf("%d ", t->item);
  }
  return 0;
}
