#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"


int main() {
	/*
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	initTree(tree);
	addNode(tree, &tree->root, 5);
	addNode(tree, &tree->root, 2);
	addNode(tree, &tree->root, 3);
	addNode(tree, &tree->root, 4);
	addNode(tree, &tree->root, 16);
	addNode(tree, &tree->root, 6);
	addNode(tree, &tree->root, 7);
	addNode(tree, &tree->root, 8);
	*/
	int i = 0;
	queue myQ;
	node_t nodes[5];

	nodes[0].data = 100;
	nodes[1].data = 50;
	nodes[2].data = 1;
	nodes[3].data = 400;
	nodes[4].data = 1100;
	
	init_q(&myQ, 5);

	for(i = 0; i < 5; i++){
		insert_q(&myQ, &nodes[i]);
	}

	for(i = 0; i < 5; i++){
		printf("%d\n", myQ.storage[i].data);
	}

	pop_q(&myQ);
	pop_q(&myQ);
	pop_q(&myQ);
	pop_q(&myQ);
	pop_q(&myQ);
	pop_q(&myQ);
	
	printf("\n\n\n\n");
	for(i = 0; i < myQ.size; i++){
		printf("%d\n", myQ.storage[i].data);
	}

	return 0;
}
