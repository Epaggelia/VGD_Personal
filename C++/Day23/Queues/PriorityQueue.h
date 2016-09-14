#ifndef __PRIORITY_QUEUE_H
#define __PRIORITY_QUEUE_H

#include "linkList.h"

template<typename T, typename CMP>
class PriorityQueue
{
public:
	PriorityQueue(int capacity)
	{

	}

	void push(T data)
	{
		if (_elements.size() == 0)
		{
			_elements.push_back(data);
		}
		else if (_elements.size() < _capacity)
		{
			LinkIterator<T> iter;
			iter = _elements.begin();

			CMP cmp;

			while (iter != _elements.end())
			{
				if (cmp(data,*iter))
				{
					break;
				}
				iter++;
			}

			if (iter == _elements.end())
			{
				_elements.push_back(data);
			}
			else
			{
				_elements.insert(iter, data);
			}
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
		return (_elements.size() == 0);
	}

private:
	LinkList<T> _elements;
	int _capacity;
};


#endif