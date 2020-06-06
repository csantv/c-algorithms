#ifndef ALGORITHMS_PRIORITY_QUEUE_H
#define ALGORITHMS_PRIORITY_QUEUE_H

typedef struct QueueNode TQueueNode;
typedef TQueueNode * TQueue;

struct QueueNode {
    int elem;
    TQueueNode * next;
};

void create_queue(TQueue*);
void enqueue(TQueue*, int);
void show_queue_elements(TQueue);
int is_empty(TQueue);
int dequeue(TQueue*);
int max_queue_elem(TQueue);

#endif
