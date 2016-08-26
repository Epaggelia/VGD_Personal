#include "Goblin.h"

using std::string;

#ifndef GOBLIN_BOSS_H
#define GOBLIN_BOSS_H

class GoblinBoss : public Goblin
{
protected:
	int _spellPower;
public:
	GoblinBoss();
	GoblinBoss(string name, int level, int health, int sepllPower);

	void attack();
	void showStatus();
	void castSpell();
};


#endif