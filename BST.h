#ifndef BinaryTree_H_INCLUDED
#define BinaryTree_H_INCLUDED

typedef struct node_T {
	int data;
	node_T *left, *right;
}node_T;

struct Tree {
	node_T *root;
	unsigned int numOfNodes, depth;
};

void initTree(struct Tree *tree);
void calcDepth(struct Tree *tree);
node_T *createNode(int data);
void addNode(struct Tree* tree, node_T **root, int data); 
void preOrder(node_T *root);
void postOrder(node_T *root);
void inOrder(node_T *root);
void levelOrder(struct Tree *tree);
node_T *searchBtree(struct Tree *tree, node_T *root, int key);
void printTree(struct Tree *tree);
void destroyTree(struct Tree *tree);

#endif