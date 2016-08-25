#include <iostream>
#include "Goblin.h"

using std::cout;
using std::endl;

Goblin::Goblin()
{
	_name = "Tony";
	_level = 1;
	_maxHealth = 10;
	_currentHealth = _maxHealth;

	cout << "A goblin was created." << endl;
}

Goblin::Goblin(string name, int level, int health)
{
	_name = name;
	_level = level < 1 ? 1 : level;
	_maxHealth = health < 1 ? 1 : health;
	_currentHealth = _maxHealth;

	cout << "A goblin was created." << endl;
}

void Goblin::attack()
{
	cout << _name << " attacks viciously!" << endl;
}

void Goblin::defend()
{
	cout << _name << " assumes a defensive stance!" << endl;
}

void Goblin::showStatus()
{
	cout << "Character Status" << endl;
	cout << "Name: " << _name << endl;
	cout << "Level: " << _level << endl;
	cout << "Health: " << _currentHealth << "/" << _maxHealth << endl;
}


