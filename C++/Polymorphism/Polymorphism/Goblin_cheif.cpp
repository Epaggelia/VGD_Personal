#include <iostream>
#include "Goblin_cheif.h"

using std::cout;
using std::endl;

GoblinCheif::GoblinCheif()
{
	_name = "David";
	_level = 7;
	_maxHealth = 100;
	_currentHealth = _maxHealth;

	_spellPower = 20;
	cout << "A goblin cheif was created." << endl;
}

GoblinCheif::GoblinCheif(string name, int level, int health, int spellPower) :GoblinBoss(name, level, health, spellPower)
{
	cout << "A goblin cheif was created." << endl;
}

void GoblinCheif::attack()
{
	cout << _name << " attack viciously, and laughs maniacally!" << endl;
}

void GoblinCheif::showStatus()
{
	Goblin::showStatus();
	cout << "Spell Power: " << _spellPower << endl;
}

void GoblinCheif::castSpell()
{
	cout << _name << " casts a powerful spell." << endl;
}

void GoblinCheif::summonMinion()
{
	if (_spellPower >= 5)
	{
		_spellPower -= 5;
		Goblin Minion("Minion", 1, 10);

		cout << endl;
		Minion.showStatus();
	}
	else
	{
		cout << "Not enough spell power to cast summon minion." << endl;
	}
}