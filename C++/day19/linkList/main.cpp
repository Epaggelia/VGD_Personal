#include <iostream>
#include "linkList.h"

using std::cout;
using std::endl;

int main()
{
	LinkList<int> my_list;

	for (int i = 0; i < 15; i++)
	{
		my_list.push_back(i * 2);
	}

	LinkIterator<int> it;

	for (it = my_list.begin(); it != my_list.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}