#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

using std::srand;
using std::rand;
using std::cout;
using std::endl;

void heapSortDescending(vector<int>& myArray);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	const int ARRAY_SIZE = 100000000;

	vector<int> myArray;
	myArray.reserve(ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		myArray.push_back(rand() % 500 + 1);
	}

	unsigned int elapsed = static_cast<unsigned int>(time(0));
	heapSortDescending(myArray);
	cout << "Array Sorted." << endl;
	cout << "Time taken: " << static_cast<unsigned int>(time(0)) - elapsed << "s" << endl;

	heapSortDescending(myArray);
	/*for (int i = 0; i < myArray.size(); i++)
	{
	cout << myArray[i] << " ";
	if ((i) % 10 == 0)
	{
	cout << endl << "i = " << i;
	cout << endl;
	}

	}*/

	cout << endl;
	system("pause");
	return 0;
}

void heapSortDescending(vector<int>& myArray)
{
	Heap<int> heap(myArray.size());

	for (int i = 0; i < myArray.size(); i++)
	{
		heap.push(myArray[i]);
	}

	for (int i = 0; i < myArray.size(); i++)
	{
		myArray[i] = heap.peek();
		heap.pop();
	}
}
