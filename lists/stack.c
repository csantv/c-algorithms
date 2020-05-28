#include <stdio.h>
#include <gc/gc.h>

#include "stack.h"

int main()
{
    TStack stack;

    create_stack(&stack);
    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 7);

    show_stack_elems(stack);
    printf("\n");
    pop(&stack);
    show_stack_elems(stack);


    return 0;
}

void create_stack(TStack* ptr_stack)
{
    *ptr_stack = NULL;
}

void push(TStack* ptr_stack, int elem)
{
    TStackNode * ptrNewNode;
    ptrNewNode = GC_malloc(sizeof(TStackNode));
    ptrNewNode->value = elem;
    ptrNewNode->next = *ptr_stack;
    *ptr_stack = ptrNewNode;
}

void show_stack_elems(TStack stack)
{
    if (stack == NULL) {
        return;
    }

    show_stack_elems(stack->next);
    printf("%d ", stack->value);
}

int is_empty(TStack* stack)
{
    return *stack == NULL;
}

int pop(TStack* stack)
{
    TStackNode * delete;
    int value = -1;

    if (!is_empty(stack)) {
        delete = *stack;
        value = delete->value;
        (*stack) = (*stack)->next;
    }

    return value;
}