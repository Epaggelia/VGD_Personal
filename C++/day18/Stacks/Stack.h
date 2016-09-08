#ifndef _STACK_H__
#define _STACK_H__

template<typename T>
class Stack
{
public:
	Stack(int size, int growBy = 1) :
		_top(-1),
		_stack(nullptr)
	{
		if (size>0)
		{
			_size = size;
			_stack = new T[_size];
			memset(_stack, 0, sizeof(T)* _size);

			_growBy = growBy > 0 ? growBy : 0;
		}
	}

	~Stack()
	{
		if (_stack != nullptr)
		{
			delete[] _stack;
		}
	}

	int empty()
	{
		return _top == -1;
	}

	int full()
	{
		return _top == _size - 1;
	}

	int size()
	{
		return _top + 1;
	}

	void push_back(T value)
	{
		if (full() == true)
		{
			expand();
		}

		_stack[++_top] = value;
	}

	void pop_back()
	{
		if (empty() == false)
		{
			_top -= 1;
		}
	}

	const T& top()
	{
		return _stack[_top];
	}

private:
	T* _stack;
	int _size;
	int _top;
	int _growBy;

	bool expand()
	{
		if (_growBy == 0)
		{
			return false;
		}

		T* temp = new T[_size + _growBy];
		memcpy(temp, _stack, sizeof(T)* _size);

		delete[] _stack;
		_stack = temp;

		_size += _growBy;
		return true;
	}
};

#endif