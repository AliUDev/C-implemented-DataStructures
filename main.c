#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main() {
	struct List *list = (struct List*)malloc(sizeof(struct List));
	initList(list);
	addFirst(list, "Ali");
	displayList(list);
	destroyList(list);
	free(list);
	
	return 0;
}
