#include<stdio.h>
#include<stdlib.h>

struct binaryTreeNode
{
	struct binaryTreeNode *left;//Used to hold left node address
	char data;//Used to hold data value
	struct binaryTreeNode *right;//Used to hold right node address
}*root = NULL;

typedef struct binaryTreeNode BTN;

BTN* prepareNewNode(char value)
{
	BTN *newNode = (BTN*) malloc(sizeof(BTN));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void preOrderTraversal(BTN *root)
{
	if(root != NULL)
	{
		printf("%c ",root->data);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void inOrderTraversal(BTN *root)
{
	if(root != NULL)
	{
		inOrderTraversal(root->left);
		printf("%c ",root->data);
		inOrderTraversal(root->right);
	}
}

void postOrderTraversal(BTN *root)
{
	if(root)
	{
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		printf("%c ",root->data);
	}
}

int levelCount(BTN *root)
{
	if(root == NULL)
		return 0;
	int llc = levelCount(root->left);
	int rlc = levelCount(root->right);
	return llc <= rlc ? rlc+1 : llc+1;
}

void printCurrentLevelData(BTN *root,int level)
{
	if(level == 1)
		printf("%c ",root->data);
	else
	{
		printCurrentLevelData(root->left,level-1);
		printCurrentLevelData(root->right,level-1);
	}
}

void levelOrderTraversal(BTN *root)
{
	int lc = levelCount(root), i;//Height of tree logic
	//printf("\nHeight: %d ",lc);
	for(i=1;i<=lc;i++)
		printCurrentLevelData(root,i);
}

int main()
{
	root = prepareNewNode('A');
	root->left = prepareNewNode('B');
	root->right = prepareNewNode('C');
	root->left->left = prepareNewNode('D');
	root->left->right = prepareNewNode('E');
	root->right->left = prepareNewNode('F');
	root->right->right = prepareNewNode('G');
	
	printf("Pre - Order Traversals: ");
	preOrderTraversal(root);
	
	printf("\nIn - Order Traversals: ");
	inOrderTraversal(root);
	
	printf("\nPost - Order Traversals: ");
	postOrderTraversal(root);
	
	printf("\nLevel - Order Traversals: ");
	levelOrderTraversal(root);
	return 0;
}
