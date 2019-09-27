#ifndef HASH_TABLE
#define HASH_TABLE
#include <stdlib.h>
#include <stdio.h>

/* Hash_Table implemented using an array of linked lists. Each Linked list will be a "bucket" to reduce chaining. The key_val pairs will be string->integer
    ex: "Name"->Age = 12
*/


/*LINKED LIST*/

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
node *peekTail(linked_list *list);
node *peekHead(linked_list *list);


/*HASH TABLE*/

typedef struct Table hash_table;


#endif