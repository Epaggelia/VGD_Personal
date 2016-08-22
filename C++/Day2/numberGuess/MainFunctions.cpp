#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int addition(int num1, int num2);
float addition(float num1, float num2);

int main()
{
	float numA, numB;

	cout << "Enter a number: " << endl;
	cin >> numA;
	cout << "Enter a number: " << endl;
	cin >> numB;

	cout << numA << " + " << numB << " = " << addition(numA, numB) << endl;

	system("PAUSE");
	return 0;
}

int addition(int num1, int num2)
{
	return num1 + num2;
}

float addition(float num1, float num2)
{
	return num1 + num2;
}