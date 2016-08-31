#include "creature.h"
#include <string>

using std::string;

#ifndef DRAGON_H
#define DRAGON_H

class Dragon : public Creature
{

public:
	Dragon(int health, int level, int damage, int defense, string type = "Dragon");
	void castSpell();
	void heal(Creature& other){}
};

#endif