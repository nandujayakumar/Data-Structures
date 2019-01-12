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
BstNode* CreateNode(int data);

/* Root node always point to the start of the tree structure */

BstNode *root = NULL;

int main()
{
    InsertElement(10);
    InsertElement(45);
    InsertElement(5);
    InsertElement(2);
    InsertElement(15);
    InsertElement(1);
    FindMin();
    FindMax();
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
        printf("Root Node Added to the Binary Tree\n");
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
