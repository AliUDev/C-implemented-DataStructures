/* 
This is a stack of names/strings that is going to be implemented using my Linked List implementation
*/

#include "LList.h"
//linked list operations


struct Stack {
	struct List storage;
	unsigned int size;
};

void initStack(struct Stack *stack) {
	initList(&stack->storage);
	stack->size = 0;
}

short empty(struct Stack *stack) {
	return stack->size == 0;
}

unsigned int size(struct Stack *stack) {
	return stack->size;
}

void pushStack(struct Stack *stack, const char *arg) {
	addFirst(&stack->storage, arg);
}

void popStack(struct Stack *stack) {
	popFirst(&stack->storage);
}

void displayStack(struct Stack *stack) {
	displayList(&stack->storage);
}
int main() {
	struct Stack stack;
	initStack(&stack);
	pushStack(&stack, "Bob");
	pushStack(&stack, "Ali");
	pushStack(&stack, "James");
	pushStack(&stack, "Son");
	pushStack(&stack, "Master");
	pushStack(&stack, "I am Groot");
	pushStack(&stack, "This name long");
	popStack(&stack);
	displayStack(&stack);
	return 0;
}