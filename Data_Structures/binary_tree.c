/* Binary tree implementation in c*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}BstNode;

void InsertElement(int data);
void InsertBetween(int data, BstNode *root);
BstNode *DeleteElement(BstNode *root,int data);
BstNode *FindMinNode (BstNode *root);
void FindMin();
void FindMax();
void PreOrder(BstNode *root);
void InOrder(BstNode *root);
void PostOrder(BstNode *root);
BstNode *CreateNode(int data);
bool IsPresent(BstNode *root,int data);
BstNode *FindParentNode(BstNode *root, int data);

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
    FindMax();
    FindMax();
    PreOrder(root);
    printf("\n");
    DeleteElement(root,10);
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

/* Insert Elements other than the root node */
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

/* Find the minimum Node containing the minimum value 
   lesser than the value in the passed argument node
*/
BstNode *FindMinNode (BstNode *root)
{
    BstNode *current = root;
    while (current -> left)
    {
        current = current -> left;
    }
    return current;
}

/*  Find the smallest element in the Binary Tree. */
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

/* Delete a node from the Binary search tree */
BstNode *DeleteElement(BstNode *root,int data)
{
  /* If the element is not present return NULL */
  if (root == NULL) return NULL ;

  else if (data < root -> data) root -> left = DeleteElement (root -> left, data);
  else if (data > root -> data) root -> right = DeleteElement (root -> right, data);
  else /* Whooah I found you....get ready to be deleted */
    {
      /* case 1 - The node to be deleted is a leaf node */
      if (!root -> left && !root -> right)
        {
          free (root);
          root = NULL;
        }
      /* Case 2 - The node to be deleted have a single child*/
      else if (root -> left == NULL)
        {
          BstNode *temp = root;
          root = root -> right;
          free (temp);
        }
      else if (root -> right == NULL)
        {
          BstNode *temp = root;
          root = root -> left;
          free (temp);
        }
      else /* Haaah...Needs more work...Case 3 - The node has two childs..*/
        {
          /* Find the minimum value in the right sub tree of the node to be deleted
             Since this is the minimum the left child of this node  will be NULL */
          BstNode *temp = FindMinNode (root -> right);
          /*Replace the node to be deleted with this data */
          root -> data = temp -> data;
          /* Delete the duplicate element in the right sub-tree */
          DeleteElement (root->right,temp-> data);
        }
    }
  return root;
}

/* check if an element is present in the tree */
bool IsPresent (BstNode *root,int key)
{
    /* Root equals to null indicated end of Tree */
    if (root == NULL )  return false ;
    else if (root -> data == key)
    {
        return true;
    }
    else if (key < root -> data)
    {
        return IsPresent(root -> left, key);
    }
    else
    {
        return IsPresent(root -> right, key);
    }
}

BstNode *FindParentNode (BstNode *root, int data)
{
    /* Check on the left sub-tree if the element is smaller */
    if (data < root -> data)
    {
        if (root -> left == NULL) return NULL;

        else if(root -> left -> data == data)
        {
            return root;
        }
        else return FindParentNode (root -> left,data);
    }

    /* Check on the right sub-tree if the element is larger */
    else
    {
        if (root -> right == NULL) return NULL;

        else if (root -> right -> data == data)
        {
            return root;
        }
        else return FindParentNode (root -> right, data);
    }
}
