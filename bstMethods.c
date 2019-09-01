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

node_t *createNode(int data){
	node_t *newNode = (node_t*)malloc(sizeof(node_t)); // allocate mem 
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void addNode(struct Tree* tree, node_t **root, int data){ //use double pointer to use existing address passed in
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

void inOrder(node_t *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d\n", root->data);
		inOrder(root->right);
	}
}
void preOrder(node_t *root){
	if(root != NULL){
		printf("%d\n", root->data);
		inOrder(root->left);
		inOrder(root->right);
	}
}

void postOrder(node_t *root){
	if(root != NULL){
		inOrder(root->left);
		inOrder(root->right);
		printf("%d\n", root->data);
	}
}

void levelOrder(struct Tree *tree) 
{ 
    queue *q = (queue *)malloc(sizeof(queue));
	node_t *temp;

	init_q(q);

	if(tree->root != NULL){
		insert_q(q, tree->root);
		
		while(!q->empty){

			temp = peek_q(q);

			printf("%d\n", temp->data);
			pop_q(q);

			if (temp->left != NULL) 
				insert_q(q, temp->left); 
	
			if (temp->right != NULL) 
				insert_q(q, temp->right);  
		}
	}

	free(q);
} 

node_t *searchBtree(struct Tree *tree, node_t *root, int key){
	node_t *retVal;

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