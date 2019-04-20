#include <iostream>
#include "binaryTree.h"

using namespace std;

int main ()
{
	binaryTree obj;
	obj.insert_element(50);
	obj.insert_element(45);
	obj.insert_element(55);
	obj.insert_element(30);
	obj.insert_element(47);
	obj.insert_element(57);
	obj.insert_element(53);
	obj.insert_element(20);
	obj.insert_element(35);
	obj.insert_element(56);
	obj.insert_element(58);
	obj.insert_element(35);
	obj.insert_element(36);
	obj.delete_element (35);
	obj.levelorder_traversal();
    cout << endl;
	
	return 0;
}
