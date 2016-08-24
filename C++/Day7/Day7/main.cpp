#include <iostream>
#include "critter.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Critter bob;

	do
	{
		system("cls");
		int userSelection;
		int userInput = NULL;

		cout << "\tCritter Caretaker." << endl;
		cout << "[1] Talk to the critter." << endl;
		cout << "[2] Feed the critter." << endl;
		cout << "[3] Entertain the critter." << endl;
		cout << "[4] Exit." << endl;
		cout << "> ";

		if (!(cin >> userSelection))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		system("cls");

		if (userSelection == 1)
		{
			bob.talk();
		}
		else if (userSelection == 2)
		{
			cout << "Pick a food: " << endl;
			cout << "\t[1] Meat" << endl;
			cout << "\t[2] Vegi" << endl;
			cout << "\t[3] Candy" << endl;
			cout << "> ";

			do
			{
				if (!(cin >> userInput))
				{
					cin.clear();
					cin.ignore(1024, '\n');
				}

				if (userInput == 1)
				{
					bob.feed(5);
					bob.passtime(0, 2);
				}
				else if (userInput == 2)
				{
					bob.feed(3);
					bob.passtime(0, 1);
				}
				else if (userInput == 3)
				{
					bob.feed(1);
					bob.passtime(0, 0);
				}
				else
				{
					cout << "Enter valid number." << endl << endl << "> ";
					userInput = NULL;
				}
			} while (userInput == NULL);
		}

		else if (userSelection == 3)
		{
			cout << "Pick something to do with your critter: " << endl;
			cout << "\t[1] Tell a joke." << endl;
			cout << "\t[2] Play fetch." << endl;
			cout << "\t[3] Go to the park." << endl;
			cout << "> ";

			do
			{
				if (!(cin >> userInput))
				{
					cin.clear();
					cin.ignore(1024, '\n');
				}

				if (userInput == 1)
				{
					bob.feed(3);
					bob.passtime(1, 0);
				}
				else if (userInput == 2)
				{
					bob.feed(4);
					bob.passtime(2, 0);
				}
				else if (userInput == 3)
				{
					bob.feed(5);
					bob.passtime(3, 0);
				}
				else
				{
					cout << "Enter valid number." << endl << endl << "> ";
					userInput = NULL;
				}
			} while (userInput == NULL);

		}
		else if (userSelection == 4)
		{
			break;
		}

		bob.passtime(1, 1);

		cout << endl;
		system("PAUSE");

	} while (true);


	system("PAUSE");
	return 0;
}