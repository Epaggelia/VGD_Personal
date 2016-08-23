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
			bob.feed(0);
		}
		else if (userSelection == 3)
		{
			bob.entertain(1);
		}
		else if (userSelection == 4)
		{
			break;
		}

		cout << endl;
		system("PAUSE");

	} while (true);


	system("PAUSE");
	return 0;
}