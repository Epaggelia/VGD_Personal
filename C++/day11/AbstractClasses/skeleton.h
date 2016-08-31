#include "creature.h"
#include <string>

using std::string;

#ifndef SKELETON_H
#define SKELETON_H

class Skeleton : public Creature
{

public:
	Skeleton(int health, int level, int damage, int defense, string type = "Skele");
	void castSpell(){}
	void heal(Creature& other){}
};
#endif