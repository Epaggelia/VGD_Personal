#include <iostream>

using std::cout;
using std::endl;

void stackAllocation();
void freeStoreAllocation();

int main()
{
	int x = 5;
	int *ptr = new int(5);

	stackAllocation();
	freeStoreAllocation();

	delete ptr;

	system("PAUSE");
	return 0;
}

void stackAllocation()
{
	cout << "Creating a million ints on the stack." << endl;
	for (int i = 0; i < 1000000; i++)
	{
		int x = i;
	}
	system("PAUSE");
}

void freeStoreAllocation()
{
	cout << "Creating a million ints on the free store." << endl;
	for (int i = 0; i < 1000000; i++)
	{
		int *x = new int(i);
	}
	system("PAUSE");
}


