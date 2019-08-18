/*
Ali Umar - 12/08/2019

Boundery conditions:
List is empty
Single element in the data structure
Adding/Removing from the beginning of the list -> handling the head
Adding/removing from the end of the data structure
Working in the middle -> most trivial


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h> // contents of our list is string
#include <stdlib.h> // needed for malloc
#include "LinkedList.h"

void initList(struct List *list) { //initializes linked list
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

unsigned int emptyList(struct List *list) {
	return list->head == NULL;
}

void addFirst(struct List *list, const char *str) {
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node)); //reserve memory on the heap

	if (newNode != NULL) { // check if malloc failed
		if (list->head == NULL) { 
			list->head = newNode;
			list->tail = newNode;
			newNode->next = NULL;
			strcpy(newNode->name, str);
			list->size++;
		}else {
			newNode->next = list->head;
			list->head = newNode;
			strcpy(newNode->name, str);
			list->size++;
		}
	}
}

void addLast(struct List *list, const char *str) {
	struct Node *newNode;

	if (list->head == NULL) {
		addFirst(list, str);
	}else {
		newNode = (struct Node *)malloc(sizeof(struct Node)); //reserve memory on the heap
		if (newNode != NULL) { // check if malloc failed
			list->tail->next = newNode;
			list->tail = newNode;
			newNode->next = NULL;
			strcpy(newNode->name, str);
			list->size++;
		}
	}
}

struct Node *popFirst(struct List *list) {
	struct Node *retVal;

	if (list->head == NULL) {
		retVal = NULL;
	}else if (list->head == list->tail) {
		retVal = list->head;
		list->head = list->tail = NULL;
		list->size--;
	}else {
		retVal = list->head;
		list->head = list->head->next;
		list->size--;
	}

	return retVal;
}

struct Node *popLast(struct List *list) {

	struct Node *retVal;
	struct Node *curr;
	struct Node *prev;

	if (list->head == NULL) {
		retVal = NULL;
	}else if (list->head == list->tail) {
		retVal = popFirst(list);
	}else {
		curr = list->head;
		prev = list->head;

		while (curr->next != NULL) { //traverse our list till the end
			prev = curr;
			curr = curr->next;
		}

		list->tail = prev;
		list->tail->next = NULL;
		retVal = curr;
		list->size--;
	}

	return retVal;
}

struct Node *find(struct List *list, const char *name) {
	struct Node *retVal;
	struct Node *curr;
	unsigned int flag = 0;

	if (list->head == NULL) {
		retVal = NULL;
	}else {
		curr = list->head;
		retVal = list->head;

		while (curr != NULL && flag == 0) {
			if (strcmp(curr->name, name) == 0) {
				retVal = curr;
				flag = 1;
				curr = curr->next;
			}else
				curr = curr->next;
		}
		
		if (flag == 0)
			retVal = NULL;
	}
	return retVal;
}

struct Node *pop(struct List *list, const char *name) { // pop by value
	struct Node *retVal;
	struct Node *curr;
	struct Node *prev;
	unsigned int flag = 0;

	if (list->head == NULL) {
		retVal = NULL;
	}else if (list->head == list->tail) {
		if (strcmp(list->head->name, name) == 0) {
			retVal = popFirst(list);
			list->size--;
		}else
			retVal = NULL;
	}else {
		// traverse the list
		curr = list->head;
		prev = NULL;
		retVal = NULL;

		while (curr != NULL && flag == 0) {
			if (strcmp(curr->name, name) == 0) {
				flag = 1;
			}else {
				prev = curr;
				curr = curr->next;
			}
		}

		if (flag == 1) {
			if (prev == NULL) // start
				retVal = popFirst(list);
			else if (curr == NULL) // end
				retVal = popLast(list);
			else {
				prev->next = curr->next;
				retVal = curr;
			}
			list->size--;
		}else
			retVal = NULL;
	}
	return retVal;
}

void displayList(struct List *mylist) {
	struct Node *temp;
	temp = mylist->head;

	while (temp != NULL) {
		printf("%s\n", temp->name);
		temp = temp->next;
	}
}

struct Node *peekFirst(struct List *list) {
	return list->head;
}

struct Node *peekLast(struct List *list) {
	return list->tail;
}
