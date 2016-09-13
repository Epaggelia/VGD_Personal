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
};



#endif