/* Binary tree implementation in c*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *left;
    struct Node *right;
}BstNode;

void InsertElement(int data);
void InsertBetween(int data, BstNode *root);
void DeleteElement(int data);
void FindMin();
void FindMax();
void PreOrder(BstNode *root);
void InOrder(BstNode *root);
void PostOrder(BstNode *root);
BstNode* CreateNode(int data);

/* Root node always point to the start of the tree structure */

BstNode *root = NULL;

int main()
{
    InsertElement(10);
    InsertElement(45);
    InsertElement(5);
    InsertElement(2);
    InsertElement(50);
    InsertElement(15);
    InsertElement(1);
    FindMin();
    DeleteElement(45);
    FindMax();
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
}

/* Create Binary tree node*/

BstNode* CreateNode(int data)
{
    BstNode* new_node = (BstNode*) malloc(sizeof(BstNode));
    new_node -> data  = data;
    new_node -> left  = NULL;
    new_node -> right = NULL;
    
    return new_node;
}

/* Insert the root node to the Binary tree */

void InsertElement(int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
    }
    else
    {
        InsertBetween(data,root);
    }
}

/* Insert Elements other than the root node*/

void InsertBetween(int data, BstNode *root)
{
    if (data < root -> data)
    {
        if (root -> left == NULL)
        {
            root -> left = CreateNode(data);
        }
        else
        {
            InsertBetween(data,root -> left);
        }
    }
    else if (data > root -> data)
    {
        if (root -> right == NULL)
        {
            root -> right = CreateNode(data);
        }
        else
        {
            InsertBetween(data,root-> right);
        }
    }
}

/*Find the smallest element in the Binary Tree */

void FindMin()
{
    BstNode *current_node = root;

    while (current_node -> left != NULL)
    {
        current_node = current_node -> left;
    }

    printf("Minimum Element is %i \n",current_node -> data);
}

/* Find the Minimum Element in the Binary tree */

void FindMax()
{
    BstNode *current_node = root;

    while (current_node -> right != NULL)
    {
        current_node = current_node -> right;
    }
    printf("Maximum Element is %i \n",current_node -> data);
}

/* Delete a node from the Binary tree */

void DeleteElement(int data)
{
}

/* Iterate in this order root, left node, right node */

void PreOrder(BstNode *root)
{
    if (root == NULL) return;
    printf("%i\t",root -> data);
    PreOrder (root -> left);
    PreOrder (root -> right);
}

/* Iterate in this order left subtree, root, right subtree */

void InOrder(BstNode *root)
{
    if (root == NULL) return;
    InOrder(root -> left);
    printf("%i\t", root -> data);
    InOrder(root -> right);
}

/* Iterate in this order left subtree, right subree and root */

void PostOrder (BstNode *root)
{
    if (root == NULL) return;
    PostOrder(root -> left);
    PostOrder(root -> right);
    printf("%i\t",root -> data);
}
