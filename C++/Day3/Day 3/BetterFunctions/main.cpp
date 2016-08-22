#include <iostream>


using std::cin;
using std::cout;
using std::endl;

void printNum(const int& x);
void getTwoNumbers(int& ref_num1, int& ref_num2);

int main()
{
	int x = 30;
	int y = 0;

	printNum(x);
	cout << x << endl;

	getTwoNumbers(x, y);
	cout << "x: " << x << endl << "y: " << y << endl;


	system("PAUSE");
	return 0;
}

void printNum(const int& x)
{
	cout << x << endl;
}

void getTwoNumbers(int& ref_num1, int& ref_num2)
{
	cout << "Please enter the first number: ";
	cin >> ref_num1;
	cout << "Please enter the second number: ";
	cin >> ref_num2;
}












