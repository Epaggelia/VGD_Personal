#include <iostream>
#include "Goblin_boss.h"

using std::cout;
using std::endl;

GoblinBoss::GoblinBoss()
{
	_name = "Kurt";
	_level = 5;
	_maxHealth = 50;
	_currentHealth = _maxHealth;

	_spellPower = 10;
	cout << "A goblin boss was created." << endl;
}

GoblinBoss::GoblinBoss(string name, int level, int health, int spellPower) :
Goblin(name, level, health)
{
	_spellPower = spellPower < 1 ? 1 : spellPower;
	cout << "A goblin boss was created." << endl;
}

void GoblinBoss::attack()
{
	cout << _name << " attack viciously, and laughs maniacally!" << endl;
}

void GoblinBoss::showStatus()
{
	Goblin::showStatus();
	cout << "Spell Power: " << _spellPower << endl;
}

void GoblinBoss::castSpell()
{
	cout << _name << " casts a powerful spell." << endl;
}