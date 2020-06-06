#include <stdio.h>
#include <gc/gc.h>

#include "double_linked_list.h"

int main()
{
    TList list;
    create_list(&list);
    append_node(&list, 6969);
    append_node(&list, 4321);
    append_node(&list, 666);
    append_node(&list, 1234);
    append_node(&list, 999);
    insert_begin(&list, 13232);
    show_list(list);
    reverse(&list);
    show_list(list);
    order_list(&list);
    show_list(list);
    return 0;
}

void order_list(TList* ptr_list)
{
    int swapped;
    TNode *ptrRunner;
    TNode *ptrLast = NULL;

    do {
        swapped = 0;
        ptrRunner = *ptr_list;
        while (ptrRunner->next != ptrLast) {
            if (ptrRunner->data > ptrRunner->next->data) {
                swap_nodes(ptrRunner, ptrRunner->next);
                swapped = 1;
            }
            ptrRunner = ptrRunner->next;
        }
        ptrLast = ptrRunner;
    } while (swapped);
}

void swap_nodes(TNode* cur1, TNode* cur2)
{
    int tmp = cur1->data;
    cur1->data = cur2->data;
    cur2->data = tmp;
}

void create_list(TList* ptr_list)
{
    *ptr_list = NULL;
}

void show_list(TList list)
{
    TNode* ptr_runner = list;
    while (ptr_runner) {
        printf("%d -> ", ptr_runner->data);
        ptr_runner = ptr_runner->next;
    }
    printf("NULL\n");
}

void append_node(TList* ptr_list, int data)
{
    TNode * new_node = GC_malloc(sizeof(TNode));
    TNode * runner = *ptr_list;
    new_node->data = data;
    new_node->next = NULL;

    if (*ptr_list == NULL) {
        new_node->prev = NULL;
        *ptr_list = new_node;
        return;
    }

    while (runner->next != NULL)
        runner = runner->next;

    runner->next = new_node;

    new_node->prev = runner;
}

int is_empty(TList list)
{
    return list == NULL;
}

void reverse(TList* ptr_list)
{
    TNode * tmp = NULL;
    TNode * curr = *ptr_list;

    while (curr != NULL) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }

    if (tmp != NULL)
        *ptr_list = tmp->prev;
}

int list_size(TList ptr_list)
{
    TNode * ptr_runner = ptr_list;
    int count = 0;
    while (ptr_runner) {
        count++;
        ptr_runner = ptr_runner->next;
    }
    return count;
}

void insert_begin(TList *ptr_list, int data)
{
    TNode* new_node = GC_malloc(sizeof(TNode));
    new_node->data = data;
    new_node->next = (*ptr_list);
    new_node->prev = NULL;
    if ((*ptr_list) != NULL)
        (*ptr_list)->prev = new_node;
    (*ptr_list) = new_node;
}