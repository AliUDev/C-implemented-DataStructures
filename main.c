#include <stdio.h>
#include <stdlib.h>
#include "include/hashTable.h"

int main() {
	linked_list list;
	initLinkedList(&list);
	insertHead(&list, "Ali Umar", 21);
	insertHead(&list, "Jason Blaha", 33);
	insertTail(&list, "Mehmood Umar", 16);
	insertTail(&list, "Fatima Umar", 45);
	removeTail(&list);
	//printLinkedList(&list);
	return 0;
}
