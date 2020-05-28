#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

typedef struct StackNode TStackNode;
typedef TStackNode* TStack;

struct StackNode {
    int value;
    TStackNode * next;
};


void create_stack(TStack*);
void push(TStack*,int);
void show_stack_elems(TStack);
int pop(TStack*);
int is_empty(TStack*);


#endif //ALGORITHMS_STACK_H
