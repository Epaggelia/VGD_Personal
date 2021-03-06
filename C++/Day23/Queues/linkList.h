#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename T> class LinkIterator;
template<typename T> class LinkList;

template<typename T>
class LinkNode
{
private:
	friend class LinkList<T>;
	friend class LinkIterator<T>;

	T _data;
	LinkNode* _next;
};

template<typename T>
class LinkIterator
{
	friend class LinkList<T>;
public:
	LinkIterator() :_node(nullptr){}

	void operator= (LinkNode<T>* node)
	{
		_node = node;
	}

	void operator++() // prefic ++iterator
	{
		_node = _node->_next;
	}

	void operator++(int) // postfix iterator++
	{
		_node = _node->_next;
	}

	bool operator==(LinkNode<T>* node)
	{
		return _node == node;
	}

	bool operator!=(LinkNode<T>* node)
	{
		return _node != node;
	}

	T& operator*() // * iterator
	{
		return _node->_data;
	}

private:
	LinkNode<T>* _node;
};

template<typename T>
class LinkList
{
public:
	LinkList() :_size(0), _root(nullptr), _last(nullptr) {};

	LinkNode<T>* begin()
	{
		return _root;
	}

	LinkNode<T>* end()
	{
		return nullptr;
	}

	void push_back(T data)
	{
		LinkNode<T> *node = new LinkNode<T>;
		node->_data = data;
		node->_next = nullptr;

		if (_last != nullptr)
		{
			_last->_next = node;
			_last = node;
		}
		else
		{
			_last = node;
			_root = node;
		}
		_size += 1;
	}

	void pop_back()
	{
		if (_root == nullptr)
		{
			return;
		}

		if (_root->_next == nullptr)
		{
			delete _root;
			_root = nullptr;
			_last = nullptr;
		}
		else
		{
			LinkNode<T>* prev = _root;

			while (prev->_next != nullptr &&prev->next != _last)
			{
				prev = prev->_next;
			}

			delete _last;
			prev->_next = nullptr;
			_last = prev;
		}
		_size -= 1;
	}

	void push_front(T data)
	{
		LinkNode<T> *node = new LinkNode<T>;

		node->_data = data;
		node->_next = nullptr;

		if (_root != nullptr)
		{
			node->_next = _root;
			_root = node;
		}
		else
		{
			_root = node;
			_last = node;
		}

		_size += 1;
	}

	void pop_front()
	{
		if (_root == nullptr)
		{
			return;
		}

		LinkNode<T> *temp = _root;
		_root = _root->_next;
		delete temp;

		_size -= 1;
	}

	void insert(LinkIterator<T>& iter, T data)
	{
		LinkNode<T>* node = new LinkNode<T>;
		
		node->_data = data;
		node->_next = iter._node;

		LinkNode<T>* temp;
		temp = _root;

		if (temp == iter._node)
		{
			_root = node;
		}
		else
		{
			while (temp->_next != iter._node)
			{
				temp = temp->_next;
			}
			temp->_next = node;
		}
		
		_size += 1;
	}

	int size()
	{
		return _size;
	}


private:
	int _size;
	LinkNode<T>* _root;
	LinkNode<T>* _last;
};

#endif