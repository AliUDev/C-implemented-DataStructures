#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
LINKED LIST METHODS UNDER THE HOOD FOR THE QUEUE IMPLEMENTATION
*/
void initList(struct List *list){
    list->head = NULL;
    list->size = 0;
}

void insertStart(struct List *list, int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(list->head == NULL){
        list->head = newNode;
        list->head->next = NULL;
        list->head->data = x;
    }else{
        newNode->next = list->head;
        newNode->data = x;
        list->head = newNode;
    }
    list->size++;
}

int popFirst(struct List *list){
    int retVal;

    struct Node *temp = list->head;

    if(list->head != NULL){
        retVal = temp->data;
        list->head = list->head->next;
        free(temp);
    }else
        retVal = 9999;
    return retVal;
}

void displayList(struct List *list){
    struct Node *temp = list->head;
    
    if(list->head != NULL){
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void destroyList(struct List *list, struct Node **head){
    struct Node* curr = *head;
    struct Node* next;

    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->size = 0;
}

/*
QUEUE METHODS
*/

void initQ(struct Queue *q){
    q->storage = (struct List*)malloc(sizeof(struct List));
    initList(q->storage);
    q->size = 0;
}

void insert(struct Queue *q, int x){
    insertStart(q->storage, x);
    q->size++;
}

int popQ(struct Queue *q){ //returns 999999999 if pop is impossible else pops first in

    int retVal;

    if(q->size > 0){
        retVal = popFirst(q->storage);
        q->size--;
    }else{
        printf("Error!! Cannot pop from empty Queue.\n");
        retVal = 9999;
    }
    
    return retVal;
}

void displayQ(struct Queue *q){
    printf("This Queue has %d elements in it.\n", q->size);
    displayList(q->storage);
}

int peekQ(struct Queue *q){
    int retVal;
    
    if(q->size > 0)
        retVal = q->storage->head->data;
    else{
        printf("Queue is empty!\n");
        retVal = 9999;
    }
    
    return retVal;
}

void freeQueue(struct Queue *q){
    printf("Freeing memory used by linked-list under this Queue\n");
    destroyList(q->storage, &q->storage->head);
    q->size = 0;
}

unsigned int getSize(struct Queue *q){
    return q->size;
}

unsigned int isEmpty(struct Queue *q){
    return q->storage->head == NULL;
}