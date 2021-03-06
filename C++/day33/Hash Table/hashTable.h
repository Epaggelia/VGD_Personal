#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class HashItem
{
public:
	HashItem() : _key(-1) {}
	~HashItem() {}

	int getKey() const { return _key; }
	void setKey(int k) { _key = k; }

	const T& getData() const { return _data; }
	void setData(const T& d) { _data = d; }

	void operator=(const HashItem& item)
	{
		_key = item._key;
		_data = item._data;
	}

	void operator==(const HashItem& item)
	{
		if (_key == item._key)
		{
			return true;
		}
		return false;
	}

private:
	int _key;
	T _data;
};

template<typename T>
class HashTable
{
public:
	HashTable(int size) : _size(0), _numElements(0), _table(nullptr)
	{
		_size = getNextPrimeNum(size);
		_table = new HashItem<T>[_size];
	}

	~HashTable()
	{
		if (_table != nullptr)
		{
			delete[] _table;
		}
	}

	bool insert(int key, const T& data)
	{
		if (_numElements >= _size)
		{
			return false;
		}

		int hash = hashFunction(key);

		while (_table[hash].getKey() != -1)
		{
			hash++;
			hash = hashFunction(hash);
		}

		_table[hash].setKey(key);
		_table[hash].setData(data);
		_numElements++;
		return true;
	}

	bool remove(int key)
	{
		int hash = hashFunction(key);
		int original = hash;

		while (_table[hash].getKey() != -1)
		{
			if (_table[hash].getKey() == key)
			{
				_table[hash].setKey(-1);
				_numElements--;
				return true;
			}

			hash++;
			hash = hashFunction(hash);

			if (original == hash)
			{
				return false;
			}
		}
		return false;
	}

	bool find(int key, T* data = nullptr)
	{
		int hash = hashFunction(key);
		int original = hash;

		while (_table[hash].getKey() != -1)
		{
			if (_table[hash].getKey() == key)
			{
				if (data != nullptr)
				{
					*data = _table[hash].getData();
				}
				return true;
			}

			hash++;
			hash = hashFunction(hash);
			if (original == hash)
			{
				return false;
			}
		}
		return false;
	}

	void displayTable() const
	{
		cout << "Table Contents" << endl;

		for (int i = 0; i < _size; i++)
		{
			cout << "Position " << i << ": ";
			if (_table[i].getKey() != -1)
			{
				cout << "Key: " << _table[i].getKey() << "\tValue: " << _table[i].getData();
			}
			else
			{
				cout << " Empty.";
			}
			cout << endl;
		}
	}

	int size()
	{
		return _size;
	}

private:
	bool isNumPrime(int val)
	{
		for (int i = 2; (i*i) <= val; i++)
		{
			if (val%i == 0)
			{
				return false;
			}
			return true;
		}
	}

	int getNextPrimeNum(int val)
	{
		int temp;
		for (int i = val + 1; /**/; i++)
		{
			if (isNumPrime(i) == true)
			{
				temp = i;
				break;
			}
		}
		return temp;
	}

	int hashFunction(int key)
	{
		return key % _size;
	}

	HashItem<T>* _table;
	int _size;
	int _numElements;
};


#endif