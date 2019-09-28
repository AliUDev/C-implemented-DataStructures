#ifndef HASH_TABLELL
#define HASH_TABLELL
/*under the hoood LINKED LIST*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    const char *key;
    int val;
    struct Node *next;
}node;

typedef struct list{
    node *head, *tail;
    unsigned int size, empty;
}linked_list;

node *createNode(const char *key, int val); //helper fn to create a node and return a pointer to craeted node
void initLinkedList(linked_list *list);
void insertHead(linked_list *list, const char *key, int val);
void insertTail(linked_list *list, const char *key, int val);
void printLinkedList(linked_list *list);
void removeHead(linked_list *list);
void removeTail(linked_list *list);
const char *peekTailKey(linked_list *list);
int peekTailVal(linked_list *list);
const char *peekHeadKey(linked_list *list);
int peekHeadVal(linked_list *list);

#endif
