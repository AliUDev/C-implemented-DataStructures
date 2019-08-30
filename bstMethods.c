#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BST.h"
#include "queue.h"

void initTree(struct Tree *tree){
	tree->depth = 0;
	tree->numOfNodes = 0;
	tree->root = NULL;
}

node_T *createNode(int data){
	node_T *newNode = (node_T*)malloc(sizeof(node_T)); // allocate mem 
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void addNode(struct Tree* tree, node_T **root, int data){ //use double pointer to use existing address passed in
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

void inOrder(node_T *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d\n", root->data);
		inOrder(root->right);
	}
}
void preOrder(node_T *root){
	if(root != NULL){
		printf("%d\n", root->data);
		inOrder(root->left);
		inOrder(root->right);
	}
}

void postOrder(node_T *root){
	if(root != NULL){
		inOrder(root->left);
		inOrder(root->right);
		printf("%d\n", root->data);
	}
}

void levelOrder(struct Tree *tree) 
{ 
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	node_T *temp = tree->root;
    if (temp != NULL){
		initQ(queue);
		insert(queue, temp->data);
	
		while (!isEmpty(queue)) 
		{ 
			// Print front of queue and remove it from queue 
			printf("%d\n", popQ(queue));
			
			if (temp->left != NULL){
				insert(queue, temp->left->data);
				temp = temp->left;
			}
	
			if (temp->right != NULL) {
				insert(queue, temp->right->data);
				temp = temp->right;
			}
		} 
	}
	free(queue);
} 

node_T *searchBtree(struct Tree *tree, node_T *root, int key){
	node_T *retVal;

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

void printTree(struct Tree *tree){ //Work in progress, will use a queue
	
}


void destroyTree(struct Tree *tree){

}