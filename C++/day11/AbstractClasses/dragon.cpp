#include "dragon.h"
#include <iostream>

using std::cout;
using std::endl;

Dragon::Dragon(int health, int level, int damage, int defense, string type) :
Creature(health, level, damage, defense, type)
{

}

void Dragon::castSpell()
{
	cout << _type << " spews fire!" << endl;
}