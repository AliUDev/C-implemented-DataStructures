#include <stdlib.h>
#include "queue.h"

void insertStart(struct List *list, int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(list->head == NULL){
        list->head = newNode;
        list->head->data = x;
    }else{
        newNode->next = list->head;
        list->head = newNode;
    }

    list->size++;
}
int popFirst(struct List *list){
    int retVal;
    struct Node *temp = list->head;

    retVal = temp->data;
    list->head = list->head->next;

    free(temp);
    return retVal;
}
void destroyList(struct List *list){

}

void initQ(queue *q, unsigned int size){
    q->storage = (int *)malloc(size * sizeof(int));
    q->size = 0;
}

void insert(queue *q, int x){

}

int popQ(queue *q){

}

int peekQ(queue *q){
}
unsigned int getSize(queue *q){

}

unsigned int isEmpty(queue *q){

}