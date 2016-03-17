#include <cstdio>
#include <cstdlib>
#include <map>

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
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void diagonalSumUtil(struct BSTNode* root, int virtD, std::map<int, int>& mapDiagonalSum)
{
    if (!root)
        return ;

    mapDiagonalSum[virtD] += root->data;
    diagonalSumUtil(root->left, virtD+1, mapDiagonalSum);
    diagonalSumUtil(root->right, virtD, mapDiagonalSum);
}

void diagonalSum(struct BSTNode* root)
{
    std::map<int, int> mapDiagSum;
    diagonalSumUtil(root, 0, mapDiagSum);

    printf("Diagonal Sum of BT is: \n");
    std::map<int, int>::iteratot itrMap = mapDiagSum.begin();
    for (; itrMap != mapDiagSum.end(); ++itrMap)
        printf("%d  ", itrMap->second);
}

int main()
{
    struct BSTNode* root = NULL;
    root = insert(root, 20);
    root = insert(root, 16);
    root = insert(root, 15);
    root = insert(root, 17);
    root = insert(root, 18);
    root = insert(root, 24);
    root = insert(root, 23);
    root = insert(root, 21);
    root = insert(root, 22);
    diagonalSum(root);
    return 0;

}
