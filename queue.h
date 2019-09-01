#ifndef Queue_H_INCLUDED
#define Queue_H_INCLUDED
#include "BST.h"

/*
This is a Queue implementation using an array. This will be a queue storing Nodes of type node_t specifically
created for level order traversal of my binary tree 
*/

typedef struct Queue{
    node_t *storage; // dynamically allocated array of node_t nodes
    node_t *front, *back;
    unsigned int size;
    unsigned int empty;
}queue;

void init_q(queue *q, unsigned int size);
void insert_q(queue *q, node_t *node);
node_t *pop_q(queue *q);
node_t *peek_q(queue *q);
unsigned int is_empty_q(queue *q);
void print_q(queue *q);
void destroy_q(queue *q);

#endif