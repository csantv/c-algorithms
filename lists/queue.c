#include <stdio.h>
#include <gc/gc.h>

#include "queue.h"

int main()
{
    TQueue ptrQueue;

    create_queue(&ptrQueue);
    enqueue(&ptrQueue, 3);
    enqueue(&ptrQueue, 8);
    enqueue(&ptrQueue, 7);
    enqueue(&ptrQueue, 19);
    enqueue(&ptrQueue, 666);

    show_queue_elements(ptrQueue);
    printf("=======\n");
    dequeue(&ptrQueue);
    show_queue_elements(ptrQueue);

    return 0;
}

void create_queue(TQueue* queue)
{
    *queue = NULL;

}

int is_empty(TQueue queue)
{
    return queue == NULL;
}

int dequeue(TQueue* queue)
{
    TQueueNode * runner, * last;
    int value = -1;

    if (!is_empty(*queue)) {
        last = NULL;
        runner = *queue;
        while (runner->next) {
            last = runner;
            runner = runner->next;
        }
        if (last == NULL)
            *queue = NULL;
        else
            last->next = NULL;
        value = runner->elem;
        return value;
    }

    return value;
}

void enqueue(TQueue* queue, int val)
{
    TQueueNode * ptrNewNode = GC_malloc(sizeof(TQueueNode));
    ptrNewNode->elem = val;
    ptrNewNode->next = *queue;
    *queue = ptrNewNode;
}

void show_queue_elements(TQueue queue)
{
    while (queue != NULL) {
        printf("Elemento: %d\n", queue->elem);
        queue = queue->next;
    }
}