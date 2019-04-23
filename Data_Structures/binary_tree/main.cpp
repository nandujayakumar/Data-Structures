#include <iostream>
#include "binaryTree.h"

using namespace std;

int main ()
{
	binaryTree obj;
	obj.insert_element(3);
	obj.insert_element(5);
	obj.insert_element(2);
	obj.insert_element(1);
	obj.insert_element(4);
	obj.insert_element(6);
	obj.insert_element(7);
    cout << endl;
    cout << obj.find_height() << endl;
	
	return 0;
}
