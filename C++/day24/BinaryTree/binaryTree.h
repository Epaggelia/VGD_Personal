#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "binaryNode.h"

using std::cout;

template<typename T>
class BinaryTree
{
public:
	BinaryTree() : _root(nullptr)
	{ }

	~BinaryTree()
	{
		if (_root != nullptr)
		{
			delete _root;
		}
	}

	bool insert(T data)
	{
		BinaryNode<T> *node = new BinaryNode<T>(data);

		if (_root == nullptr)
		{
			_root = node;
			return true;
		}
		else
		{
			BinaryNode<T> *parent = nullptr;
			BinaryNode<T> *current = _root;
			while (true)
			{
				parent = current;
				if (data == current->_data)
				{
					delete node;
					return false;
				}

				if (data < current->_data)
				{
					current = current->_left;

					if (current == nullptr)
					{
						parent->_left = node;
						return true;
					}
				}
				else
				{
					current = current->_right;

					if (current == nullptr)
					{
						parent->_right = node;
						return true;
					}
				}
			}
		}
	}

	bool remove(T data)
	{
		if (_root == nullptr)
			return false;

		BinaryNode<T> *parent = nullptr;
		BinaryNode<T> *current = _root;
		bool isLeft = false;

		while (current->data != data)
		{
			parent = current;

			if (data < current->data)
			{
				current = current->_left;
				isLeft = true;
			}
			else
			{
				current = current->_right;
				isLeft = false;
			}

			if (current == nullptr)
				return false;
		}

		if (current->_left == nullptr && current->_right == nullptr)
		{
			if (current == _root)
				_root = nullptr;
			else if (isLeft)
				parent->_left = nullptr;
			else
				parent->_right = nullptr;
		}
		else if (current->_left == nullptr)
		{
			if (current == _root)
				_root = current->_right;
			else if (isleft)
				parent->_left = current->_right;
			else
				parent->_right = current->_right;
		}
		else if (current->_right == nullptr)
		{
			if (current == _root)
				_root = current->_left;
			else if (isLeft)
				parent->_left = current->_left;
			else
				parent->_right = current->_left;
		}
		else
		{
			BinaryNode<T> *temp = current->_right;
			BinaryNode<T> *successor = current;
			BinaryNode<T> *sParent = current;
			while (temp != nullptr)
			{
				sParent = successor;
				successor = temp;
				temp = temp->_left;
			}

			if (successor != current->_right)
			{
				sParent->_left = successor->_right;
				successor->_right = current->_right;
			}

			if (current == _root)
			{
				_root = successor;
			}
			else if (isLeft)
			{
				current = parent->_left;
				parent->_left = successor;
			}
			else
			{
				current = parent->_right;
				parent->_right = successor;
			}

			successor->_left = current->_left;
		}

		current->_left = nullptr;
		current->_right = nullptr;
		delete current;
		return true;
	}

	void display()
	{
		if (_root == nullptr)
		{
			cout << "Nothing to display.\n";
		}
		else
		{
			display(_root);
			cout << "End of display.\n";
		}
	}

private:
	BinaryNode<T>* _root;

	void display(BinaryNode<T>* node)
	{
		if (node != nullptr)
		{
			cout << node->_data << " ";
			display(node->_left);
			cout << "// \n";
			display(node->_right);
		}
	}
};



#endif