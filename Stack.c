/* 
This is a stack of names/strings that is going to be implemented using my Linked List implementation
*/

#include "LinkedList.h"
//linked list operations
void initList(struct List *list);
void addFirst(struct List *list, const char *str);
void addLast(struct List *list, const char *str);
struct Node *popFirst(struct List *list);
struct Node *popLast(struct List *list);
struct Node *find(struct List *list, const char *name);
struct Node *pop(struct List *list, const char *name);
void display(struct List *mylist);
struct Node *peekFirst(struct List *list);
struct Node *peekLast(struct List *list);

struct Stack {
	struct List storage;
	unsigned int size;
};




int main() {
	return 0;
}