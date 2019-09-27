#include "include/hashTable.h"

node *createNode(const char *key, int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;   //new node will not point to anything
    newNode->key = key;
    newNode->val = val;
}

void initLinkedList(linked_list *list){
    list->empty = 1; // flag list as empty
    list->head = list->tail = NULL;
    list->size = 0;
}

void insertHead(linked_list *list, const char *key, int val){
    if(list->empty){
        list->head = list->tail = createNode(key, val);
        list->empty = 0;
    }else{  
        node *temp = createNode(key, val);
        temp->next = list->head;
        list->head = temp;
    }
    list->size++;
}

void insertTail(linked_list *list, const char *key, int val){
    if(list->empty)
        insertHead(list, key, val);
    else{
        list->tail->next = createNode(key, val);
        list->tail = list->tail->next;
    }
    list->size++;
}

void printLinkedList(linked_list *list){
    if(list->empty){
        printf("Empty");
    }else{
        node *temp = list->head;
        printf("[\n");
        while(temp != NULL){
            printf("{%s, %d}\n", temp->key, temp->val);
            temp = temp->next;
        }
        printf("]");
    }
}

void removeHead(linked_list *list){
    if(list->empty)
        printf("Cannot remove from an empty list\n");
    else if(list->head == list->tail){
        free(list->head);
        list->head = list->tail = NULL;
        list->size = 0;
        list->empty = 1;
    }else{
        node *temp = list->head->next;
        free(list->head);
        list->head = temp;
        list->size--;
    }
}

void removeTail(linked_list *list){
    if(list->empty)
        printf("Cannot remove from an empty list\n");
    else if(list->head == list->tail){
        removeHead(list);
    }else{
        node *temp = list->head;
        while(temp->next != list->tail){
            temp = temp->next;
        }
        free(list->tail);
        list->tail = temp;
    }
}

const char *peekTailKey(linked_list *list){
    return list->tail->key;
}

const int *peekTailVal(linked_list *list){
    return list->tail->val;
}
const char *peekHeadKey(linked_list *list){
    return list->head->key;
}

const int *peekHeadVal(linked_list *list){
    return list->head->val;
}