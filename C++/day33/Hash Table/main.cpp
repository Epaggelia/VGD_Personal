#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "hashTable.h"

using std::srand; 
using std::rand;
using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	const int TABLE_SIZE = 20;
	HashTable<int> table(TABLE_SIZE);

	for (int  i = 0; i < TABLE_SIZE; i++)
	{
		table.insert(i * 10 + 100, rand() % TABLE_SIZE);
	}

	table.displayTable();

	system("pause");
	return 0;
}