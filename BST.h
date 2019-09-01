#ifndef BinaryTree_H_INCLUDED
#define BinaryTree_H_INCLUDED

typedef struct tree_node {
	int data;
	struct tree_node *left, *right;
}node_t;

struct Tree {
	node_t *root;
	unsigned int numOfNodes, depth;
};

void initTree(struct Tree *tree);
void calcDepth(struct Tree *tree);
node_t *createNode(int data);
void addNode(struct Tree* tree, node_t **root, int data); 
void preOrder(node_t *root);
void postOrder(node_t *root);
void inOrder(node_t *root);
void levelOrder(struct Tree *tree);
node_t *searchBtree(struct Tree *tree, node_t *root, int key);
void printTree(struct Tree *tree);
void destroyTree(struct Tree *tree);

#endif