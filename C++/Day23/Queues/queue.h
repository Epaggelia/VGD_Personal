#ifndef __QUEUE_H
#define __QUEUE_H

#include "linkList.h"

template<typename T>
class Queue
{
public:
	Queue(int capacity)
	{
		_capacity = capacity;
	}

	void push(T data)
	{
		if (_elements.size() < _capacity)
		{
			_elements.push_back(data);
		}
	}

	void pop()
	{
		_elements.pop_front();
	}

	const T& front()
	{
		LinkIterator<T> iter;
		iter = _elements.begin();

		return (*iter);
	}

	int size()
	{
		return _elements.size();
	}

	int capacity()
	{
		return _capacity;
	}

	bool empty()
	{
		return(_elements.size() == 0);
	}

private:
	LinkList<T> _elements;
	int _capacity;
};


#endif