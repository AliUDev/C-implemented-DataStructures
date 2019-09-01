#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"

int main() {
	
	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	initTree(tree);
	addNode(tree, &tree->root, 10);
	addNode(tree, &tree->root, 2);
	addNode(tree, &tree->root, 12);
	addNode(tree, &tree->root, 1);
	addNode(tree, &tree->root, 8);
	levelOrder(tree);
	free(tree);
	//inOrder(tree->root);
	return 0;
}
