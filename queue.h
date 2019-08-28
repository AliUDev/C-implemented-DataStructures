#ifndef Queue_H_INCLUDED
#define Queue_H_INCLUDED

/*
This is a Queue implementation using a linked list specifically
created for level order traversal of my binary tree 
*/

/*LINKED LIST STRUCTURE FOR QUEUE IMPLEMENTATION & Methods */

#ifndef NODE_DEF
#define NODE_DEF
struct Node{
    int data;
    struct Node *next;
};
#endif
struct List {
	int size;
    struct Node *head;
};

/*Only methods necessary for Queue will be coded*/

void initList(struct List *list);
void insertStart(struct List *list, int x);
int popFirst(struct List *list);
void destroyList(struct List *list, struct Node **head);

/*Queue Structure & Methods*/

struct Queue {
	struct List *storage;
	unsigned int size;
};

void initQ(struct Queue *q);
void insert(struct Queue *q, int x);
int popQ(struct Queue *q);
int peekQ(struct Queue *q);
void displayQ(struct Queue *q);
unsigned int getSize(struct Queue *q);
unsigned int isEmpty(struct Queue *q);
void freeQueue(struct Queue *q);


#endif