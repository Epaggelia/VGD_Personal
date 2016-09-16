#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template<typename T>
class BinaryTree;

template<typename T>
class BinaryNode
{
	friend class BinaryTree<T>;
public:
	BinaryNode(T data) :
		_data(data), _left(nullptr), _right(nullptr)
	{ }

	~BinaryNode()
	{
		if (_left != nullptr)
		{
			delete _left;
			_left = nullptr;
		}

		if (_right != nullptr)
		{
			delete _right;
			_right = nullptr;
		}
	}

	const T& getData() const
	{
		return _data;
	}

private:
	T _data;
	BinaryNode *_left, *_right;
};


#endif