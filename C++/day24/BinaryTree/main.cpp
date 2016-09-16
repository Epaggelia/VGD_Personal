#include "binaryTree.h"
#include <iostream>

using std::cout; 
using std::endl;



int main()
{
	BinaryTree<int> tree;

	tree.insert(12);
	tree.insert(21);
	tree.insert(120);
	tree.insert(32);
	tree.insert(43);
	tree.insert(12);
	tree.insert(45);
	tree.insert(67);
	tree.insert(34);
	tree.insert(368);
	tree.insert(2);

	tree.display();

	system("pause");
	return 0;
}