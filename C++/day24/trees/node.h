#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;

template<typename T>
class Node
{
public:
	Node(T data) :
		_data(data), _next(nullptr), _prev(nullptr), _child(nullptr)
	{}
	~Node()
	{
		_prev = nullptr;

		if (_child != nullptr)
		{
			delete _child;
			_child = nullptr;
		}

		if (_next != nullptr)
		{
			delete _next;
			_next = nullptr;
		}
	}

	void addChild(Node *node)
	{
		if (_child == nullptr)
		{
			_child = node;
		}
		else
		{
			_child->addSibling(node);
		}
	}

	void addSibling(Node *node)
	{
		Node *temp = _next;

		if (temp == nullptr)
		{
			_next = node;
			node->_prev = this;
		}
		else
		{
			while (temp->_next != nullptr)
			{
				temp = temp->_next;
			}

			temp->_next = node;
			node->_prev = temp;
		}
	}

	bool search(T data)
	{
		if (_data == data)
		{
			return true;
		}

		if (_child != nullptr)
		{
			if (_child->search(data))
				return true;
		}

		if (_next!=nullptr)
		{
			if (_next->search(data))
				return true;
		}

		return false;
	}

	void displayTree()
	{
		cout << _data;

		if (_next != nullptr)
		{
			cout << " ";
			_next->displayTree();
		}

		if (_child != nullptr)
		{
			cout << "\n";
			_child->displayTree();
		}
	}
private:
	T _data;
	Node *_next, *_prev, *_child;
};


#endif