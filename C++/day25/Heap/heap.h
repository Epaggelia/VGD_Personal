#ifndef __HEAP_H
#define __HEAP_H

#include <vector>

using std::vector;

template<typename T>
class Heap
{
public:
	Heap();
	Heap(int minSize)
	{
		_heap.reserve(minSize);
	}

	void push(T data)
	{
		_heap.push_back(data);

		int index = _heap.size() - 1;
		T temp = _heap[index];
		int parentIndex = (index - 1) / 2;

		while (index > 0 && temp >= _heap[parentIndex])
		{
			_heap[index] = _heap[parentIndex];
			index = parentIndex;
			parentIndex = (parentIndex - 1) / 2;
		}
		_heap[index] = temp;
	}

	void pop()
	{
		int index = 0;

		_heap[index] = _heap[(int)_heap.size() - 1];
		_heap.pop_back();

		if (_heap.size() == 0)
		{
			return;
		}

		T temp = _heap[index];

		int currentIndex = 0;
		int leftIndex = 0;
		int rightIndex = 0;

		while (index < _heap.size() /2)
		{
			leftIndex = 2 * index + 1;
			rightIndex = leftIndex + 1;

			if (rightIndex < _heap.size() && _heap[rightIndex] > _heap[leftIndex])
			{
				currentIndex = rightIndex;
			}
			else
			{
				currentIndex = leftIndex;
			}

			if (temp >= _heap[currentIndex])
			{
				break;
			}
		
			_heap[index] = _heap[currentIndex];
			index = currentIndex;
		}
		_heap[index] = temp;
	}

	const T& peek()
	{
		return _heap[0];
	}

	int size()
	{
		return (int)_heap.size();
	}

private:
	vector<T> _heap;
};

#endif
