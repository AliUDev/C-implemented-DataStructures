#include "stack.h"
#include "LinkedList.h"

int main() {
	struct Stack stack;
	const char *name;
	initStack(&stack);
	displayStack(&stack);
	return 0;
}