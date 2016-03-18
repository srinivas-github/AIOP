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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct BSTNode* insert(struct BSTNode* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct BSTNode* lca(struct BSTNode* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

int main()
{
    struct BSTNode* root = NULL;
    root = insert(root, 14);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 16);
    root = insert(root, 17);
    struct BSTNode* lcaNode = lca(root, 17, 13);
    printf("LCA of 17 and 13 is: %d\n", lcaNode->data);
    return 0;

}

