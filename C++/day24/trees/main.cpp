#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

int main()
{
	Node<int> *root = new Node<int>(1);
	Node<int> *subtree = new Node<int>(3);

	root->addChild(new Node<int>(15));

	subtree->addChild(new Node<int>(10));
	subtree->addChild(new Node<int>(20));

	root->addChild(subtree);
	root->addChild(new Node<int>(4));

	cout << "Tree contents by level: " << endl;
	root->displayTree();
	cout << endl;

	cout << root->search(20) << "\n";
	cout << root->search(2) << "\n";

	system("pause");
	return 0;
}

