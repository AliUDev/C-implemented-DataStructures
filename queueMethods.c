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

void init_qlist(q_list *list){
    list->head = list->tail = NULL;
    list->size = 0;
}

node_q *create_nodeq(node_t *node){
    node_q *qNode = (node_q*)malloc(sizeof(node_q));
    qNode->node = node;
    qNode->next = NULL;
    return qNode;
}

void insert_head_qlist(q_list *list, node_t *node){
    if(list->head == NULL)
        list->head = list->tail = create_nodeq(node);
    else{
        node_q *temp = create_nodeq(node);
        temp->next = list->head;
        list->head = temp;
    }
    list->size++;
}

node_t *remove_head_qlist(q_list *list){
    node_t *retVal;

    if(list->head == NULL)
        retVal = NULL;
    else if(list->head == list->tail){
        retVal = list->head;
        list->head = list->tail = NULL;
    }else{
        
    }
}
node_q *get_qlist_head(q_list *list);
void destroy_qlist(q_list *list);


void init_q(queue *q, unsigned int size){
    q->storage = (q_list *)malloc(sizeof(q_list));
    q->front = q->back =  q->storage->head;
    q->size = 0;
    q->empty = 1;
}

void insert_q(queue *q, node_t *node){
   if(q->empty){
       q->storage = &node;
       q->front = q->back = *q->storage;
       q->empty = 0;
   }else{
       q->storage[q->size] = node;
       q->back = q->storage[q->size];
   }
   q->size++; 
}

node_t *pop_q(queue *q){
    node_t *retVal;

    if(q->size == 1){
        retVal = q->front;
        q->front = q->back = *q->storage;
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