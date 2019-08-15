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
#include <string.h>
#include <stdlib.h> // needed for malloc

struct Node {
	char name[20];
	struct Node *next;
};

struct List {
	struct Node *head;
	struct Node *tail;
	unsigned int size;
};

struct List list; // create my list 

void initList() { //initializes linked list
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
}

void addFirst(const char *str) {
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node)); //reserve memory on the heap

	if (newNode != NULL) { // check if malloc failed
		if (list.head == NULL) { 
			list.head = newNode;
			list.tail = newNode;
			newNode->next = NULL;
			strcpy(newNode->name, str);
			list.size++;
		}
		else {
			newNode->next = list.head;
			list.head = newNode;
			strcpy(newNode->name, str);
			list.size++;
		}
	}
}

void addLast(const char *str) {
	if (list.head == NULL) {
		addFirst(str);
	}else {
		struct Node *newNode;
		newNode = (struct Node *)malloc(sizeof(struct Node)); //reserve memory on the heap
		if (newNode != NULL) { // check if malloc failed
			list.tail->next = newNode;
			list.tail = newNode;
			newNode->next = NULL;
			strcpy(newNode->name, str);
			list.size++;
		}
	}
}

int main(){
	initList();
	addLast("Herbert");
	addLast("Alice");
	addLast("James");
	addLast("Bob");
	addLast("Jew");
	addLast("PeePee");
	addLast("Master");
	addFirst("Super Man");
	printf("The size of my list is : %d\n", list.size);

	while (list.head != NULL) {
		printf("%s\n", list.head->name);
		list.head = list.head->next;
	}
	return 0;
}