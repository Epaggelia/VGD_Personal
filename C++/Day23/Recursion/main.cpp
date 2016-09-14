#include <iostream>

using std::cout;
using std::endl;

void countdown(int number);
int factorial(int x);

int main()
{
	countdown(10);

	cout << endl;

	cout << factorial(5);

	cout << endl;

	system("pause");
	return 0;
}

void countdown(int number)
{
	if (number <= 0)
	{
		return;
	}
	cout << number << " ";
	countdown(number - 1);
}

int factorial(int x)
{
	if (x > 1)
	{
		return x * factorial(x - 1);
	}
	else
	{
		return 1;
	}
}