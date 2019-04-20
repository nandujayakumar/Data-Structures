#include <iostream>
#include "binaryTree.h"
#include <queue>

using namespace std;

void binaryTree :: insert_element (int data, Bstnode *current)
{
	/* If the tree is empty add the new node as root node */
	if (current == NULL)
	{
		Bstnode *temp = new Bstnode(data);
		root = temp;
		return;
	}
	else
	{
		if (data < current -> data)
		{
			if (current->left == NULL)
			{
				Bstnode *temp = new Bstnode(data);
				current -> left = temp;
				return;
			}
			insert_element (data, current -> left);
		}
		else if (data > current -> data)
		{
			if (current->right == NULL)
			{
				Bstnode *temp = new Bstnode(data);
				current -> right = temp;
				return;
			}
			insert_element (data, current -> right);
		}
	}
}

void binaryTree:: preorder_traversal(Bstnode *current)
{
	if (current != NULL)
	{
		cout << current -> data << " " ;
		preorder_traversal (current -> left);
		preorder_traversal (current -> right);
	}
}

void binaryTree:: inorder_traversal(Bstnode *current)
{	
	if (current != NULL)
	{
		inorder_traversal (current -> left);
		cout << current -> data << " ";
		inorder_traversal (current -> right);
	}
}

void binaryTree:: postorder_traversal(Bstnode *current)
{	
	if (current != NULL)
	{
		postorder_traversal (current -> left);
		postorder_traversal (current -> right);
		cout << current -> data << " ";
	}
}

void binaryTree :: levelorder_traversal(Bstnode *root)
{
	/* Use a queue to keep track of reference to  left and right sub-tree */
	queue <Bstnode *> Q;
	Q.push(root);
	while (!Q.empty())
	{
		Bstnode *temp = Q.front();
		cout << temp -> data << " " ;
		if (temp -> left != NULL) Q.push(temp->left);
		if (temp -> right != NULL) Q.push (temp -> right);
		Q.pop();
	}
}

Bstnode* binaryTree :: delete_element (int data, Bstnode *current)
{
	if (current == NULL) return NULL;
	else if (data < current -> data)
	{
		current -> left = delete_element (data, current -> left);
	}
	else if (data > current -> data)
	{
		current -> right = delete_element (data, current -> right);
	}
	else /*Whooah ! found you get ready to be deleted */
	{
		/* The node is a leaf node */
		if (current -> left == NULL && current -> right == NULL)
		{
			delete current;
			current = NULL;
		}
		/* Either one of the child node is not empty */
		else if (current -> left == NULL)
		{
			Bstnode *temp = current;
			current = current -> right;
			delete temp;
		}
		else if (current -> right == NULL)
		{
			Bstnode *temp = current;
			current = current -> left;
			delete temp;
		}
		/* Both the child nodes are not empty */
		else
		{
            /* Find the minimum value in the right sub-tree */
            Bstnode *temp = find_min_node (current -> right);
 
            /* copy the inorder successor value to this node */
            current -> data = temp -> data;

            /* Delete the inorder successor */
            current -> right = delete_element (temp -> data , current -> right);
		}
	}
	return current;
}

Bstnode* binaryTree :: find_min_node (Bstnode *current)
{
	cout << current -> data << endl;
	return current;
}

int binaryTree :: find_min_element()
{
	Bstnode *current = root;
	while (current -> left != NULL)
	{
		current = current -> left;
	}
	return current -> data;
}

int binaryTree :: find_max_element()
{
	Bstnode *current = root;
	while (current -> right != NULL)
	{
		current = current -> right;
	}
	return current -> data;
}

Bstnode *find_min_node(Bstnode *current)
{
    while (current -> left)
    {
        current = current -> left;
    }
    
    return current;
}












