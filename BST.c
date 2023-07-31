#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node 
{
    int data;
    struct Node *left, *right;
};

struct Node* getNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* LevelOrder(struct Node* root, int data)
{
    if (root == NULL) 
    {
        root = getNode(data);
        return root;
    }
    if (data <= root->data)
        root->left = LevelOrder(root->left, data);
    else
        root->right = LevelOrder(root->right, data);
    return root;
}

struct Node* constructBst(int arr[], int n)
{
    if (n == 0)
        return NULL;
    struct Node* root = NULL;

    for (int i = 0; i < n; i++)
        root = LevelOrder(root, arr[i]);

    return root;
}

void inOrderTraversal(struct Node* root)
{
    if(!root)
        return;

    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct Node* root)
{
    if (!root)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root)
{
    if (!root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void print2DUtil(struct Node* root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

 
    print2DUtil(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    print2DUtil(root->left, space);
}

void print2D(struct Node* root)
{
    print2DUtil(root, 0);
}

int main()
{
    int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = constructBst(arr, n);
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    print2D(root);
    return 0;
}
