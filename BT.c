#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node
{
    int data;
    struct Node*left,*right;
};

struct Node* newNode(int data)
{
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return(node);
}

struct Node*insertLevelOrder(int arr[],int i,int n)
{
      struct Node*root = NULL;
    
    if(i<n)
    {
        root=newNode(arr[i]);
        root->left=insertLevelOrder(arr,2 * i + 1, n);
        root->right=insertLevelOrder(arr,2 * i + 2, n);
    }
    return root;
}

void inOrder(struct Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
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

    for(int i = COUNT; i < space; i++)
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
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = insertLevelOrder(arr, 0, n);
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    print2D(root);
}