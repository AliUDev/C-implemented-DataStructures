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

/*********************************************************
 * Linked list methods under the hood of the queue
 * 
 * *******************************************************
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

void insert_tail_qlist(q_list *list, node_t *node){
    if(list->head == NULL)
        insert_head_qlist(list, node);
    else{
        node_q *temp = create_nodeq(node);
        list->tail->next = temp;
        list->tail = temp;
    }
    list->size++;
}

void pop_head_qlist(q_list *list){
    node_q *temp;
    if(list->head == NULL)
        printf("Cannot pop from an empty list.");
    else if(list->head == list->tail){
        free(list->head);
        list->head = list->tail = NULL;
        list->size--;
    }else{
        temp = list->head->next;
        free(list->head);
        list->head = temp;
        list->size--;
    }
}

node_q *get_qlist_head(q_list *list){
    return list->head;
}
void destroy_qlist(q_list *list){
    node_q *temp = list->head;
    while(temp != NULL){
        free(temp);
        temp = list->head->next;
    }
}

/****************************************************************************//*
                                    Queue methods*/
/****************************************************************************/

void init_q(queue *q){
    q->storage = (q_list *)malloc(sizeof(q_list));
    q->size = 0;
    q->empty = 1;
}

void insert_q(queue *q, node_t *node){
    if(q->empty){
        insert_head_qlist(q->storage, node);
        q->empty = 0;
    }else{
        insert_tail_qlist(q->storage, node);
    }
    q->size++;
}

void pop_q(queue *q){
    if(q->empty)
        printf("Cannot pop from an empty queue");
    else{
        pop_head_qlist(q->storage);
        q->size--;

        
    }
    
    q->empty = q->size == 0;
}

node_t *peek_q(queue *q){
    return q->storage->head->node;
}

void destroy_q(queue *q){
    free(q->storage);
}