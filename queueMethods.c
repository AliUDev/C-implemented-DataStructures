#include <stdlib.h>
#include "queue.h"
void initList(struct List *list){
    list->head = NULL;
    list->size = 0;
}
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
    struct Node *temp = list->head;

    printf("Destroying list...");
    while(list->head != NULL){
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void initQ(struct Queue *q){
    q->storage = (struct List*)malloc(sizeof(struct List));
    initList(q->storage);
    q->size = 0;
}
void insert(struct Queue *q, int x);
int popQ(struct Queue *q);
int peekQ(struct Queue *q);
unsigned int getSize(struct Queue *q);
unsigned int isEmpty(struct Queue *q);