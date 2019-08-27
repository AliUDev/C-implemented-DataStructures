#ifndef BinaryTree_H_INCLUDED
#define BinaryTree_H_INCLUDED

#ifndef NODE_DEF
#define NODE_DEF

struct Node {
	int data;
	struct Node *left, *right;
};
#endif

struct Tree {
	struct Node *root;
	unsigned int numOfNodes, depth;
};

void initTree(struct Tree *tree);
void calcDepth(struct Tree *tree);
struct Node *createNode(int data);
void addNode(struct Tree* tree, struct Node **root, int data); 
void preOrder(struct Node *root);
void postOrder(struct Node *root);
void inOrder(struct Node *root);
struct Node *searchBtree(struct Tree *tree, struct Node *root, int key);
void printTree(struct Tree *tree);
void destroyTree(struct Tree *tree);

#endif