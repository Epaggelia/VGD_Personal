#include <iostream>
#include "critter.h"

using std::cout;
using std::cin;
using std::endl;

Critter::Critter(int hunger, int boredom)
{
	if (hunger < 0)
		_hunger = 0;
	else
		_hunger = hunger;

	if (boredom < 0)
		_boredom = 0;
	else
		_boredom = boredom;
}

void Critter::talk()
{
	int mood;

	mood = _hunger + _boredom;

	cout << "I'm feeling ";
	if (mood > 15)
	{
		cout << "terrible";
	}
	else if (mood > 10)
	{
		cout << "loasy";
	}
	else if (mood > 5)
	{
		cout << "ok";
	}
	else
	{
		cout << "great";
	}
	cout << "." << endl << endl;

	cout << "Hunger: " << _hunger << endl;
	cout << "Boredom: " << -_boredom << endl;
}

void Critter::feed(int food)
{
	int userInput = 0;
	
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
			food = 5;
		}
		else if (userInput == 2)
		{
			food = 3;
		}
		else if (userInput == 3)
		{
			food = 1;
			_boredom -= 1;
		}
		else
		{
			food = 0;
		}
	} while (food == 0);

	_hunger -= food;
	cout << "Hunger decreased by " << food << "." << endl << "\tCurrently " << _hunger << " hunger." << endl;
	if (userInput == 3)
		cout << "Boredom decreased by 1." << endl;
}

void Critter::entertain(int fun)
{
	if (fun > 0)
		_boredom -= fun;
}

void Critter::passtime(int hunger, int boredom)
{
	//todo
}

