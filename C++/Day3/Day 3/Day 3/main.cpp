#include <iostream>


using std::cin;
using std::cout;
using std::endl;

float addTwoNumbers(float num1,float num2);
float subtractTwoNumbers(float num1, float num2);
float multiplyTwoNumbers(float num1, float num2);
float divideTwoNumbers(float num1, float num2);

int main()
{
	int userSelection = 0;
	float input1, input2;
	int pause = 0;

	do {
		cout << "\tSimple Calculator." << endl << endl;
		cout << "[1] Add Two Numbers." << endl;
		cout << "[2] Subtract Two Numbers." << endl;
		cout << "[3] Multiply Two Numbers." << endl;
		cout << "[4] Divide Two Numbers." << endl;
		cout << "[5] Exit." << endl;

		cout << "Your selection: ";
		cin >> userSelection;
		system("cls");

		if (userSelection > 5 || userSelection < 1)
		{
			cout << "You have failed at a simple task." << endl << "You should try that again." << endl << endl << endl;
			continue;
		}

		if (userSelection == 5)
		{ 
			break;
		}

		cout << "Enter a number! ";
		cin >> input1;
		cout << "ANOTHER! ";
		cin >> input2;

		switch (userSelection)
		{
		case 1:
			cout << endl << "Added numbers = " << addTwoNumbers(input1, input2) << endl << endl;
			break;
		case 2:
			cout << endl << "Subtracted numbers = " << subtractTwoNumbers(input1, input2) << endl << endl;
			break;
		case 3:
			cout << endl << "Multiplied numbers = " << multiplyTwoNumbers(input1, input2) << endl << endl;
			break;
		case 4:
			cout << endl << "Divided numbers = " << divideTwoNumbers(input1, input2) << endl << endl;
			break;
		default:
			break;
		}
		
		cout << "[1] Continue" << endl;
		cout << "[2] Exit" << endl;
		cin >> pause;

		if (pause == 1)
		{
			system("cls");
			continue;
			
		}
		else if (pause == 2)
		{
			system("cls");
			break;
		}
		
		
	} while (true);

	system("PAUSE");
	return 0;
}

float addTwoNumbers(float num1, float num2)
{
	return num1 + num2;
}

float subtractTwoNumbers(float num1, float num2)
{
	return num1 - num2;
}

float multiplyTwoNumbers(float num1, float num2)
{
	return num1 * num2;
}

float divideTwoNumbers(float num1, float num2)
{
	if (num2 != 0)
	{
		return num1 / num2;
	}
	
	cout <<  "Error can't divide by zero!" << endl;
	return 0.0f;
}

