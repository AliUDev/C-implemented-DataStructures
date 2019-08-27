	#ifndef LinkedList_H_INCLUDED
	#define LinkedList_H_INCLUDED
	
	#ifndef NODE_DEF
	#define NODE_DEF
	struct Node {
		char name[20];
		struct Node *next;
	};
	#endif

	struct List {
		struct Node *head;
		struct Node *tail;
		unsigned int size;
	};

	void initList(struct List *list);
	void addFirst(struct List *list, const char *str);
	void addLast(struct List *list, const char *str);
	void displayList(struct List *mylist);
	unsigned int emptyList(struct List *myList);
	struct Node *popFirst(struct List *list);
	struct Node *popLast(struct List *list);
	struct Node *find(struct List *list, const char *name);
	struct Node *pop(struct List *list, const char *name);
	struct Node *peekFirst(struct List *list);
	struct Node *peekLast(struct List *list);
	void destroyList(struct List *list);

	#endif