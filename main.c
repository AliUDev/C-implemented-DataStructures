#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"


int main() {
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
	levelOrder(tree);
	return 0;
}
