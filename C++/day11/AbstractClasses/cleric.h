#include "creature.h"
#include <string>

using std::string;

#ifndef CLERIC_H
#define CLERIC_H

class Cleric : public Creature
{
protected:
	int _healingPower;
public:
	Cleric(int health, int level, int damage, int defense, int healing, string type = "Cleric");
	
	void castSpell();
	void heal(Creature& other);
};

#endif