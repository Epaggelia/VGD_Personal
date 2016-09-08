#include <iostream>
#include <string>
#include"Stack.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
	Stack<int> my_stack(5);
	Stack<char> my_words(5);

	for (int i = 0; i < 15; i++)
	{
		my_stack.push_back(i * 2);
	}
	for (int i = 0; i < 256; i++)
	{
		my_words.push_back(i);
	}

	cout << "Stack size: " << my_stack.size() << endl;

	for (int i = my_stack.size(); i > 0; i--)
	{
		cout << my_stack.top() << " ";
		my_stack.pop_back();
	}

	cout << endl;

	for (int i = my_words.size(); i > 0; i--)
	{
		cout << i-1 << ": " << my_words.top() << " \t";
		my_words.pop_back();
		if (my_words.size() % 10 == 0)
			cout << endl;
	}

	system("pause");
	return 0;
}