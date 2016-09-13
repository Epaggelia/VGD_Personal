#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "unorderedArray.h"

using std::cout;
using std::endl;
using std::rand;
using std::srand;

template<typename T>
void print(UnorderedArray<T>& arrayRef);

template<typename T>
void bubbleSort(UnorderedArray<T>& arrayRef);

template<typename T>
void selectionSort(UnorderedArray<T>& arrayRef);

template<typename T>
void insertionSort(UnorderedArray<T>& arrayRef);

int main()
{
	const int ARRAY_SIZE = 15;
	srand(static_cast<unsigned int>(time(0)));

	UnorderedArray<int> myArray(ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		myArray.push_back(rand() % 100 + 1);
	}

	print<int>(myArray);

	unsigned int elapsed = static_cast<unsigned int> (time(0));
	insertionSort<int>(myArray);
	cout << "Array sorted." << endl;
	cout << "Time take: " << static_cast<unsigned int>(time(0)) - elapsed << "s" << endl;

	print<int>(myArray);

	system("pause");
	return 0;
}

template<typename T>
void print(UnorderedArray<T>& arrayRef)
{
	for (int i = 0; i < arrayRef.size(); i++)
	{
		cout << arrayRef[i] << " ";
	}
	cout << endl;
}

template<typename T>
void bubbleSort(UnorderedArray<T>& arrayRef)
{
	T temp;
	for (int i = arrayRef.size() - 1; i > 0; i--)
	{
		for (int k = 0; k < i; k++)
		{
			if (arrayRef[k] > arrayRef[k + 1])
			{
				temp = arrayRef[k];
				arrayRef[k] = arrayRef[k + 1];
				arrayRef[k + 1] = temp;
			}
		}
	}
}

template<typename T>
void selectionSort(UnorderedArray<T>& arrayRef)
{
	T temp;
	int min = 0;

	for (int  i = 0; i < arrayRef.size()-1; i++)
	{
		min = i;
		for (int j = i +1; j < arrayRef.size(); j++)
		{
			if (arrayRef[j] < arrayRef[min])
			{
				min = j;
			}
		}
		if (arrayRef[i] > arrayRef[min])
		{
			temp = arrayRef[i];
			arrayRef[i] = arrayRef[min];
			arrayRef[min] = temp;
		}
	}
}

template<typename T>
void insertionSort(UnorderedArray<T>& arrayRef)
{
	T temp;
	int i = 0;

	for (int j = 1; j < arrayRef.size(); j++)
	{
		temp = arrayRef[j];
		i = j;

		while (i > 0 && arrayRef[i-1] >= temp)
		{
			arrayRef[i] = arrayRef[i - 1];
			i--;
		}
		arrayRef[i] = temp;
	}
}