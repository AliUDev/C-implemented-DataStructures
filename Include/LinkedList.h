	#ifndef LinkedList_H_INCLUDED
	#define LinkedList_H_INCLUDED

	typedef struct node_L {
		char name[20];
		node_L *next;
	}node_L;

	struct List {
		node_L *head;
		node_L *tail;
		unsigned int size;
	};

	void initList(struct List *list);
	void addFirst(struct List *list, const char *str);
	void addLast(struct List *list, const char *str);
	void displayList(struct List *mylist);
	unsigned int emptyList(struct List *myList);
	node_L *popFirst(struct List *list);
	node_L *popLast(struct List *list);
	node_L *find(struct List *list, const char *name);
	node_L *pop(struct List *list, const char *name);
	node_L *peekFirst(struct List *list);
	node_L *peekLast(struct List *list);
	void destroyList(struct List *list);

	#endif