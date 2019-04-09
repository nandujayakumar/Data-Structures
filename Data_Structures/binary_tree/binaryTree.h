#ifndef BINARY_H
#define BINARY_H

class Bstnode
{
	public:
			int data;
			Bstnode *left;
			Bstnode *right;
			
			// initialize the values of the node, returns a pointer to the node
			Bstnode(int value): data(value),left(NULL),right(NULL){} 
};

class binaryTree
{
	private:
			Bstnode *root = NULL;
			void insert_element (int,Bstnode *);
			void inorder_traversal (Bstnode *);
			void preorder_traversal (Bstnode *);
			void postorder_traversal (Bstnode *);
			void levelorder_traversal (Bstnode *);
			Bstnode* delete_element (int data, Bstnode *);
	public:
			void insert_element (int data) {insert_element (data,root);}
			void inorder_traversal () {inorder_traversal(root);}
			void preorder_traversal () {preorder_traversal (root);}
			void postorder_traversal () {postorder_traversal (root);}
			void levelorder_traversal () {levelorder_traversal (root);}
			void delete_element (int data) {delete_element (data, root);}
			Bstnode* find_min_node (Bstnode *);
			int find_min_element();
			int find_max_element();
};

#endif