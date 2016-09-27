#include "unorderedArray.h"
#include <iostream>
#include "stdlib.h"
#include <time.h>

using std::srand;
using std::rand;
using std::cout;
using std::endl;

template<typename T>
void print(UnorderedArray<T> &arrayRef);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	const int ARRAY_SIZE = 10000000;
	UnorderedArray<int> myArray(ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		myArray.push_back(rand() % ARRAY_SIZE);
	}

	cout << "Sorting array." << endl;

	unsigned int elapsed = static_cast<unsigned int>(time(0));
	myArray.sort();
	unsigned int takenTime = static_cast<unsigned int>(time(0)) - elapsed;

	//print<int>(myArray);
	cout << "Array sorted";
	cout << "Time taken: " << takenTime << "s" << endl;

	system("pause");
	return 0;
}


template<typename T>
void print(UnorderedArray<T> &arrayRef)
{
	for (int i = 0; i < arrayRef.size(); i++)
	{
		cout << arrayRef[i] << " ";
	}

	cout << endl;
}