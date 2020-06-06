#include "priority_queue.h"
#include <stdio.h>
#include <gc/gc.h>
#include <limits.h>

int main()
{
    TQueue ptrQueue;

    create_queue(&ptrQueue);
    enqueue(&ptrQueue, 3);
    enqueue(&ptrQueue, 8);
    enqueue(&ptrQueue, 19);
    enqueue(&ptrQueue, 7);
    enqueue(&ptrQueue, 666);
    enqueue(&ptrQueue, 14);
    enqueue(&ptrQueue, 666);
    printf("%d\n", max_queue_elem(ptrQueue));

    show_queue_elements(ptrQueue);
    printf("=======\n");
    dequeue(&ptrQueue);
    show_queue_elements(ptrQueue);
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
    TQueueNode * runner = *queue, * prev = NULL;
    if (is_empty(*queue)) {
        return -1;
    }
    int max_index = max_queue_elem(*queue);
    int i = 0;
    while (runner->next) {
        if (i == max_index) break;
        prev = runner;
        runner = runner->next;
        i++;
    }
    if (!prev) {
        *queue = runner->next;
    } else {
        prev->next = runner->next;
    }
    return runner->elem;
}

// devolver el indice del ultimo mayor de la cola
int max_queue_elem(TQueue queue)
{
    int max = INT_MIN;
    int i = 0;
    while (queue != NULL) {
        if (queue->elem >= max) {
            max = queue->elem;
            i++;
        }
        queue = queue->next;
    }
    return i;
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
        printf(" %d ->", queue->elem);
        queue = queue->next;
    }
    printf("\n");
}
