/* 
This is a stack that is going to be implemented using my Linked List implementation
*/

#include "LinkedList.h"

int main() {
	struct Node *temp;
	initList();

	addLast("Element 1");
	addLast("Element 2");
	addLast("Element 3");
	addLast("Element 4");
	addLast("Element 5");
	addLast("Element 6");
	addLast("Element 7");
	addLast("Element 8");
	temp = peekLast();
	display(&list);
	return 0;
}