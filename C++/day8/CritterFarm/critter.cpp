#include <iostream>
#include "critter.h"

using std::cout;
using std::cin;
using std::endl;

Critter::Critter(string name, int hunger, int boredom)
{
	_name = name;

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

	cout << _name << " is feeling ";
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
	cout << "Boredom: " << _boredom << endl;
}

void Critter::feed(int food)
{

	if (food > 0 && food <= _hunger)
	{
		cout << "Yum, that was tasty." << endl;
		_hunger -= food;
	}
	else if (food > _hunger)
	{
		cout << "That's more then I can eat" << endl;
		_hunger = 0;
	}

	cout << "\tHunger decreased by " << food << "." << endl << "\tCurrently " << _hunger << " hunger." << endl;
	cout << "\tCurrently " << _boredom << " boredom." << endl;
}

void Critter::entertain(int fun)
{
	

	if (fun > 0 && fun <= _boredom)
	{
		cout << "Wee! That was fun!" << endl;
		_boredom -= fun;
	}
	else if (fun > _boredom)
	{
		cout << "I don't have the energy for something like that." << endl;
		_boredom = 0;
	}

	_boredom -= fun;
}

void Critter::passtime(int hunger, int boredom)
{
	_hunger += hunger;
	_boredom += boredom;
}

string Critter::getName()
{
	return _name;
}