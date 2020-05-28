#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H

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

#endif //ALGORITHMS_QUEUE_H
