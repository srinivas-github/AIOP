#include <cstdio>
#include <cstdlib>

struct BSTNode
{
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

struct BSTNode* newNode(int data)
{
    struct BSTNode* temp = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLeaves(struct BSTNode* root)
{
    if (root)
    {
        printLeaves(root->left);
	if ( !(root->left) && !(root->right))
	    printf("%d  ", root->data);
	printLeaves(root->right);
    }
}

void printBoundaryLeft(struct BSTNode* root)
{
    if (root)
    {
        if (root->left)
	{
	    printf("%d  ", root->data);
	    printBoundaryLeft(root->left);
	}
	else if (root->right)
	{
	    printf("%d  ", root->data);
	    printBoundaryLeft(root->right);
	}
    }
}

void printBoundaryRight(struct BSTNode* root)
{
    if (root)
    {
        if (root->right)
	{
	    printBoundaryRight(root->right);
	    printf("%d  ", root->data);
	}
	else if(root->left)
	{
	    printBoundaryRight(root->left);
	    printf("%d  ", root->data);
	}
    }
}

void printBoundary(struct BSTNode* root)
{
    if (root)
    {
        printf("%d  ", root->data);
	printBoundaryLeft(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	printBoundaryRight(root->right);
    }
}

int main()
{
    struct BSTNode* root = NULL;
    root = newNode(28);
    root->left = newNode(26);
    root->left->left = newNode(24);
    root->left->right = newNode(25);

    root->right = newNode(36);
    root->right->left = newNode(34);
    root->right->right = newNode(38);
    printBoundary(root);
    return 0;
}
