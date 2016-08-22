//pointer stuff
#include <iostream>

using std::cout;
using std::endl;

int* badReturn();

int main()
{
	

	int x = 15;
	int *p = &x;

	cout << "x: " << x << endl <<
		"*p: " << *p << endl <<
		"&p: " << &p << endl <<
		"p: " << p << endl << endl;

	int numbers[5] = { 10, 20, 30, 40, 50 };

	p = numbers; 

	cout << "numbers[2]: " << numbers[2] << endl;
	cout << "*(p+2): " << *(p + 2) << endl;

	p = badReturn();

	system("PAUSE");

	cout << *p << endl;

	system("PAUSE");
	return 0;
}


int* badReturn()
{
	int myValue = 100;
	return &myValue;
}


