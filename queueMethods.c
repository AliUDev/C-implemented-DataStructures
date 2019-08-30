#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


void init_q(queue *q, unsigned int size){
    q->storage = (node_t *)calloc(size, sizeof(node_t)); //array of size
    q->front = &q->storage[0];
    q->back = &q->storage[0];
    q->size = 0;
    q->empty = 1;
}

void insert_q(queue *q, node_t *node){
    if(q->empty == 1){
        q->front = node;
        q->back = node;
        q->storage = node;
        q->empty = 0;
    }else{
        q->back = node;
        q->storage[q->size] = *node;
    }
    q->size++;
}

node_t pop_q(queue *q){
    int i;
    node_t retVal;

    if(q->size > 0){
        q->front = (q->storage + 1);
        retVal = *q->front;
        //shift array
        for(i = 0; i < q->size; i++){
            q->storage[i] = q->storage[i+1];
        }

        q->front = q->storage;
        q->back = (q->storage + q->size);
        q->size--;
    }else
        printf("Cannot pop from empty queue");

    return retVal;
}
node_t *peek_q(queue *q);
void destroy_q(queue *q);