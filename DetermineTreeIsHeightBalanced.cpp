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

struct BSTNode* insert(struct BSTNode* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data <= root->data )
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct BSTNode* root)
{
    if (root == NULL)
      return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(struct BSTNode* root)
{
    if (root == NULL)
        return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if ( abs(lh -rh) <= 1 &&
         isBalanced(root->left) && isBalanced(root->right))
	 return 1;

    return 0;
}

int main()
{
    struct BSTNode* node = NULL;
    node = insert(node, 19);
    node = insert(node, 17);
    node = insert(node, 21);
    node = insert(node, 15);
    node = insert(node, 20);
    node = insert(node, 18);
    node = insert(node, 22);

    isBalanced(node) ? printf("Height is Balanced\n"):printf("Height is not Balanced\n");
    return 0;
}
