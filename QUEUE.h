// Program 4.18
// First-class ADT interface for queues

#ifndef QUEUE_H
#define QUEUE_H

#include "item_int.h"

typedef struct queue *Q;

Q QUEUEinit(int);
int QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);

#endif
