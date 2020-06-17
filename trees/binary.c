// C-Algorithms , algoritmos en C que uso
// Copyright (C) 2020   Carlos Toro
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <gc/gc.h>

#include "binary.h"

int main()
{
    TBinaryTree* tree;
    create_binary_tree(&tree);
    if (is_empty(tree))
        printf("El arbol esta vacio!\n");

    insert(&tree, 12);
    insert(&tree, 16);
    insert(&tree, 7);
    insert(&tree, 4);
    insert(&tree, 20);
    insert(&tree, 9);

    printf("Imprimir en preorden: ");
    print_preorder(tree->root);
    printf("\n");

    printf("Imprimir en orden: ");
    print_inorder(tree->root);
    printf("\n");

    printf("Imprimir en postorden: ");
    print_postorder(tree->root);
    printf("\n");

    if (!is_empty(tree))
        printf("El arbol no esta vacio!\n");

    if (is_present(tree, 5)) {
        printf("El valor 5 esta presente.\n");
    }

    insert(&tree, 8);
    printf("Imprimir en orden: ");
    print_inorder(tree->root);
    printf("\n");

    remove_node(&tree, 7);
    printf("Imprimir en preorden: ");
    print_preorder(tree->root);
    printf("\n");

    printf("Imprimir en orden: ");
    print_inorder(tree->root);
    printf("\n");

    printf("Imprimir en postorden: ");
    print_postorder(tree->root);
    printf("\n");

    printf("La altura del arbol es %d. \n", height(tree->root));

    printf("El peso del arbol es %d.\n", weight(tree->root));

    return 0;
}

void remove_node(TBinaryTree** tree, int value)
{
    TNode * aux = (*tree)->root;
    TNode * p = NULL;

    // avanzar hasta el nodo con el valor requerido
    while (aux) {
        if (aux->info == value) break;

        p = aux;
        if (value < aux->info) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    if (!aux) return; // no hacer nada si no se encontro

    // primer caso, el nodo es una hoja
    if (!aux->left && !aux->right) {
        // el nodo es la raiz
        if (!p) {
            (*tree)->root = NULL;
        } else {
            if (p->left == aux) {
                p->left = NULL;
            } else if (p->right == aux) {
                p->right = NULL;
            }
        }
        return;
    }

    // el nodo tiene 1 solo hijo por la izquierda
    if (aux->left && !aux->right) {
        // el nodo es la raiz
        if (!p) {
            (*tree)->root = aux->left;
        } else {
            if (p->left == aux) {
                p->left = aux->left;
            } else if (p->right == aux) {
                p->right = aux->left;
            }
        }
        return;
    }

    // el nodo tiene 1 solo hijo por la derecha
    if (!aux->left && aux->right) {
        // el nodo es la raiz
        if (!p) {
            (*tree)->root = aux->right;
        } else {
            if (p->left == aux) {
                p->left = aux->right;
            } else if (p->right == aux) {
                p->right = aux->right;
            }
        }
        return;
    }

    // en el caso que el nodo a eliminar tenga 2 hijos
    TNode * q = aux->left;
    while (q->right)
        q = q->right;

    int data = q->info;
    remove_node(tree, data);

    aux->info = data;
}

int weight(TNode* node)
{
    if (!node) return 0;

    return 1 + weight(node->left) + weight(node->right);
}

int height(TNode* node)
{
    if (!node) return 0;

    int left_height = height(node->left);
    int right_height = height(node->right);

    return 1 + max(left_height, right_height);
}

bool is_present(TBinaryTree* tree, int info)
{
    TNode * aux = tree->root;
    while (aux) {
        if (aux->info == info) return true;

        if (info < aux->info) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    return false;
}

void print_postorder(TNode* node)
{
    if (!node) return;
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->info);
}

void print_inorder(TNode* node)
{
    if (!node) return;
    print_inorder(node->left);
    printf("%d ", node->info);
    print_inorder(node->right);
}

void print_preorder(TNode* node)
{
    if (!node) return;
    printf("%d ", node->info);
    print_preorder(node->left);
    print_preorder(node->right);
}

void create_binary_tree(TBinaryTree** tree)
{
    *tree = GC_malloc(sizeof(TBinaryTree));
    (*tree)->root = NULL;
}

void insert(TBinaryTree** tree, int data)
{
    TNode * new_node = GC_malloc(sizeof(TNode));
    new_node->left = NULL;
    new_node->left = NULL;
    new_node->info = data;

    TNode * aux = (*tree)->root;
    TNode * father = NULL;

    while (aux) {
        father = aux;
        if (data <= aux->info) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    if (!father) {
        (*tree)->root = new_node;
    } else {
        if (data <= father->info) {
            father->left = new_node;
        } else {
            father->right = new_node;
        }
    }
}

bool is_empty(TBinaryTree* tree)
{
    return tree->root == NULL;
}