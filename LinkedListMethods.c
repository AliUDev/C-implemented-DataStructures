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
	node_L *newNode;
	newNode = (node_L *)malloc(sizeof(node_L)); //reserve memory on the heap

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
	node_L *newNode;

	if (list->head == NULL) {
		addFirst(list, str);
	}else {
		newNode = (node_L *)malloc(sizeof(node_L)); //reserve memory on the heap
		if (newNode != NULL) { // check if malloc failed
			list->tail->next = newNode;
			list->tail = newNode;
			newNode->next = NULL;
			strcpy(newNode->name, str);
			list->size++;
		}
	}
}

node_L *popFirst(struct List *list) {
	node_L *retVal;

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

node_L *popLast(struct List *list) {

	node_L *retVal;
	node_L *curr;
	node_L *prev;

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

node_L *find(struct List *list, const char *name) {
	node_L *retVal;
	node_L *curr;
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

node_L *pop(struct List *list, const char *name) { // pop by value
	node_L *retVal;
	node_L *curr;
	node_L *prev;
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

void displayList(struct List *list) {
	node_L *temp;
	temp = list->head;

	while (temp != NULL) {
		printf("%s\n", temp->name);
		temp = temp->next;
	}
}

void destroyList(struct List *list){
	printf("Destroying List..!");
	
	while(list->head != NULL){
		free(list->head);
		list->head = list->head->next;
	}
}

node_L *peekFirst(struct List *list) {
	return list->head;
}

node_L *peekLast(struct List *list) {
	return list->tail;
}
