#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/* A queue holding

typedef struct node_t {
	int data;
	node_t *left, *right;
}node_t;

created for my bianry search tree implementation. It dynamically allocated an array depending on the number of nodes in the tree.

*/

void init_q(queue *q, unsigned int size){
    q->storage = (node_t *)calloc(size, sizeof(node_t)); //array of size
    q->front = q->back =  q->storage;
    q->size = 0;
    q->empty = 1;
}

void insert_q(queue *q, node_t *node){
   if(q->empty){
       q->storage[0] = *node;
       q->front = q->back = q->storage;
       q->empty = 0;
   }else{
       q->storage[q->size] = *node;
       q->back = &q->storage[q->size - 1];
   }
   q->size++; 
}

node_t *pop_q(queue *q){
    node_t *retVal;

    if(q->size == 1){
        retVal = q->front;
        q->front = q->back = q->storage;
        q->size--;
        q->empty = 1;
    }else if(!q->empty){
        retVal = q->front;
        q->front += 1;
        q->size--;
    }else{
        printf("You cannot pop from an empty Queue.");
        retVal = NULL;
    }

    return retVal;
}

void print_q(queue *q){
    printf("First in queue: %d\n", q->front->data);
    printf("Last in queue: %d\n", q->back->data);
}
node_t *peek_q(queue *q){
    return q->front;
}

void destroy_q(queue *q){
    free(q->storage);
}