#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void initTree(struct Tree *tree){
	tree->depth = 0;
	tree->numOfNodes = 0;
	tree->root = NULL;
}

struct Node *createNode(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // allocate mem 
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void addNode(struct Tree* tree, struct Node **root, int data){ //pass in the root of the tree
	if(*root == NULL){
		*root = createNode(data);
		tree->numOfNodes++;
		calcDepth(tree);
	}else{
		if(data < (*root)->data){
			addNode(tree, &(*root)->left, data);
		}else{
			addNode(tree, &(*root)->right, data);
		}
	}
}

void inOrder(struct Node *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d\n", root->data);
		inOrder(root->right);
	}
}
void preOrder(struct Node *root){
	if(root != NULL){
		printf("%d\n", root->data);
		inOrder(root->left);
		inOrder(root->right);
	}
}
void postOrder(struct Node *root){
	if(root != NULL){
		inOrder(root->left);
		inOrder(root->right);
		printf("%d\n", root->data);
	}
}

struct Node *searchBtree(struct Tree *tree, struct Node *root, int key){
	struct Node *retVal;

	if(tree->numOfNodes != 0){
		if(key == root->data)
			retVal = root;
		else{
			if(key < root->data)
				retVal = searchBtree(tree, root->left, key);
			else
				retVal = searchBtree(tree, root->right, key);
		}
	}else
		retVal = NULL;
	
	return retVal;
}


void calcDepth(struct Tree *tree){
	if(tree->root == NULL)
		tree->depth = 0;
	else
		tree->depth = (int) (log(tree->numOfNodes) / log(2)) + 1;
}
