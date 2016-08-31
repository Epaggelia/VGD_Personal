#include <iostream>
#include "creature.h"
#include "skeleton.h"
#include "imp.h"
#include "dragon.h"
#include "cleric.h"

using std::cout; 
using std::endl;

void makeFight(Creature& fighter1, Creature& fighter2);
void makeHeal(Creature& healer, Creature& healed);

int main()
{
	Skeleton skel(15, 1, 3, 1);
	Imp imp(7, 1, 1, 1);
	Dragon drag(100,10,10,10);
	Cleric cler(30, 1, 5, 2, 5);

	cout << "An Imp and Skeleton are fighting." << endl;
	makeFight(skel, imp);
	cout << endl << "A dragon shows up with his cleric friend." << endl;
	makeFight(drag, imp);
	makeFight(drag, skel);
	makeFight(cler, skel);
	makeHeal(cler, drag);

	system("PAUSE");
	return 0;
}

void makeFight(Creature& fighter1, Creature& fighter2)
{
	fighter1.attack(fighter2);
	fighter2.attack(fighter1);
	fighter1.castSpell();
	fighter2.castSpell();
}

void makeHeal(Creature& healer, Creature& healed)
{
	healer.heal(healed);
}