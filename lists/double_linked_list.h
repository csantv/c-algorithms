#ifndef ALGORITHMS_DOUBLE_LINKED_LIST_H
#define ALGORITHMS_DOUBLE_LINKED_LIST_H

typedef struct Tnode TNode;
typedef TNode* TList;


struct Tnode {
    int data;
    TNode* next;
    TNode* prev;
};

void create_list(TList* ptr_list);
void show_list(TList ptr_list);
void append_node(TList* ptr_list, int data);
int is_empty(TList list);
void insert_begin(TList *ptr_list, int data);
void reverse(TList* ptr_list);
int list_size(TList ptr_list);
void order_list(TList* ptr_list);
void swap_nodes(TNode*,TNode*);

#endif
