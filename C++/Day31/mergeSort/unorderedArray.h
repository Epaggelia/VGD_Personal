#ifndef UNORDERED_ARRAY_H
#define UNORDERED_ARRAY_H

template <typename T>
class UnorderedArray
{
public:
	UnorderedArray(int size, int growSize = 1) :
		_array(nullptr), _maxSize(0), _growSize(0), _numElements(0)
	{
		if (size > 0)
		{
			_maxSize = size;
		}
		else
		{
			_maxSize = 1;
		}
		_array = new T[_maxSize];
		memset(_array, 0, sizeof(T)* _maxSize);

		_growSize = growSize > 0 ? growSize : 0;
	}
	
	~UnorderedArray()
	{
		if (_array != nullptr)
		{
			delete[] _array;
		}
	}

	void push_back(T value)
	{
		if (_numElements >= _maxSize)
		{
			if (expand() == false)
			{
				return;
			}
		}

		_array[_numElements++] = value;
	}

	void pop_back()
	{
		if (_numElements > 0)
		{
			_numElements -= 1;
		}
	}

	void remove(int index)
	{
		if (index >= _numElements || index < 0)
		{
			return;
		}
	
		for (int i = index; i < _numElements -1; i++)
		{
			array[i] = array[i+ 1];
		}

		_numElements -= 1;
	}

	int size()
	{
		return _numElements;
	}

	int capacity()
	{
		return _maxSize;
	}

	void clear()
	{
		_numElements = 0;
	}

	T& operator[](unsigned int index)
	{
		return _array[index];
	}

	void sort()
	{
		T* tempArray = new T[_numElements];

		mergeSort(tempArray, 0, _numElements - 1);
		delete[] tempArray;
	}

private:
	T* _array;

	int _maxSize;
	int _growSize;
	int _numElements;

	bool expand()
	{
		if (_growSize <=0)
		{
			return false;
		}

		T* temp = new T[_maxSize + _growSize];
		memcpy(temp, _array, sizeof(T)* _maxSize);
		delete[] _array;

		_array = temp;
		_maxSize += _growSize;
		return true;
	}

	void mergeSort(T* tempArray, int lowerbound, int upperBound)
	{
		if (lowerbound == upperBound)
		{
			return;
		}

		int mid = (lowerbound + upperBound) / 2;

		mergeSort(tempArray, lowerbound, mid);
		mergeSort(tempArray, mid + 1, upperBound);
		merge(tempArray, lowerbound, mid + 1, upperBound);
	}

	void merge(T*  tempArray, int low, int mid, int upper)
	{
		int tempLow = low;
		int tempMid = mid - 1;
		int index = 0;

		while (low <= tempMid && mid <= upper)
		{
			if (_array[low] <= _array[mid])
			{
				tempArray[index++] = _array[low++];
			}
			else
			{
				tempArray[index++] = _array[mid++];
			}
		}

		while (low <= tempMid)
		{
			tempArray[index++] = _array[low++];
		}

		while (mid <= upper)
		{
			tempArray[index++] = _array[mid++];
		}

		for (int i = 0; i < upper - tempLow + 1; i++)
		{
			_array[tempLow + i] = tempArray[i];
		}
	}
};



#endif