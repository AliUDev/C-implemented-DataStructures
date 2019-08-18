#ifndef Stack_H_INCLUDED
#define Stack_H_INCLUDED

#include "LinkedList.h"

struct Stack {
	struct List storage;
	unsigned int size;
};

void initStack(struct Stack *stack);
short empty(struct Stack *stack);
unsigned int size(struct Stack *stack);
void pushStack(struct Stack *stack, const char *arg);
void popStack(struct Stack *stack);
void displayStack(struct Stack *stack);


#endif