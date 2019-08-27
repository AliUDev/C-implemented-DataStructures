#include <stdlib.h>
#include "stack.h"

void initStack(struct Stack *stack) {
	initList(&stack->storage);
	stack->size = 0;
}

short empty(struct Stack *stack) {
	return emptyList(&stack->storage);
}

unsigned int size(struct Stack *stack) {
	return stack->size;
}

void pushStack(struct Stack *stack, const char *arg) {
	addFirst(&stack->storage, arg);
}

const char *popStack(struct Stack *stack) {
	const char *retVal;
	struct Node *temp = popFirst(&stack->storage);
	if (!empty(stack)) {
		retVal = temp->name;
	}else {
		retVal = NULL;
	}
	return retVal;
}

void displayStack(struct Stack *stack) {
	if (stack->size == 0)
		printf("The stack is empty, please fill it up");
	else
		displayList(&stack->storage);
}