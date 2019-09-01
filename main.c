#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"

int main() {
	
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	initTree(tree);
	addNode(tree, &tree->root, 10);
	addNode(tree, &tree->root, 7);
	addNode(tree, &tree->root, 6);
	addNode(tree, &tree->root, 5);
	addNode(tree, &tree->root, 22);
	addNode(tree, &tree->root, 29);
	addNode(tree, &tree->root, 200);
	addNode(tree, &tree->root, 8);
	addNode(tree, &tree->root, 9);
	levelOrder(tree);
	//inOrder(tree->root);
	
/*
	queue *q = (queue *)malloc(sizeof(queue));
	node_t nodes[10];
	node_t *temp;
	
	nodes[0].data = 100;
	nodes[1].data = 50;
	nodes[2].data = 10;
	nodes[3].data = 9;;
	nodes[4].data = 1;
	nodes[5].data = 45;
	nodes[6].data = 65;
	nodes[7].data = 80;
	nodes[8].data = 11;
	nodes[9].data = 13;
	
	init_q(q, 10);

	for(int i = 0; i < 10; i++)
		insert_q(q, &nodes[i]);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	pop_q(q);
	//pop_q(q);
	print_q(q);
*/
	return 0;
}
