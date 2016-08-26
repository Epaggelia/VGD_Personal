#include "Goblin_boss.h"

using std::string;

#ifndef GOBLIN_CHEIF_H
#define GOBLIN_CHEIF_H

class GoblinCheif : public GoblinBoss
{
public:
	GoblinCheif();
	GoblinCheif(string name, int level, int health, int spellPower);

	void attack();
	void showStatus();
	void castSpell();
	void summonMinion();
};


#endif