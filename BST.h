#ifndef BinaryTree_H_INCLUDED
#define BinaryTree_H_INCLUDED
// ensures only one node structure is in scope at a time
#ifndef NODE_DEF
#define NODE_DEF

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
#endif

struct Tree {
	struct Node *root;
	unsigned int depth;
	unsigned int numOfNodes;
};

void initTree(struct Tree *tree);
struct Node *createNode(int data);
void addNode(struct Node **root, int data); 
void preOrder(struct Node *root);
void postOrder(struct Node *root);
void inOrder(struct Node *root);

#endif