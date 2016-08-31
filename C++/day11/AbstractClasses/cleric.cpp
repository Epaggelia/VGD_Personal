#include "cleric.h"
#include <iostream>

using std::cout;
using std::endl;

Cleric::Cleric(int health, int level, int damage, int defense, int healing,  string type) :
Creature(health, level, damage, defense, type)
{
	_healingPower = healing;
}

void Cleric::castSpell()
{
	cout << _type << " also spews fire!" << endl;
}


void Cleric::heal(Creature& other)
{
	cout << _type << " heals " <<  other.type() << " for " << _healingPower << " hp." << endl;
}