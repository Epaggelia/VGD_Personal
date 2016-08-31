#include "creature.h"
#include <string>

using std::string;

#ifndef IMP_H
#define IMP_H

class Imp : public Creature
{

public:
	Imp(int health, int level, int damage, int defense, string type = "Imp");
	void castSpell();
	void heal(Creature& other){}
};

#endif