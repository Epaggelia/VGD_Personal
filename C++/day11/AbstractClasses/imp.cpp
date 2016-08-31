#include "imp.h"
#include <iostream>

using std::cout;
using std::endl;

Imp::Imp(int health, int level, int damage, int defense, string type) :
Creature(health, level, damage, defense, type)
{

}

void Imp::castSpell()
{
	cout << _type << " casts a spell!" << endl;
}