#include <iostream>
#include "Goblin.h"
#include "Goblin_boss.h"
#include "Goblin_cheif.h"

using std::cout;
using std::endl;

int main()
{
	Goblin gob1;
	cout << endl;
	Goblin gob2("Chad", 2, 18);
	cout << endl;
	GoblinBoss gob3;
	cout << endl;
	GoblinCheif gob4;
	cout << endl;

	gob1.attack();
	gob1.defend();
	gob1.showStatus();
	cout << endl;

	gob2.attack();
	gob2.defend();
	gob2.showStatus();
	cout << endl;

	gob3.attack();
	gob3.defend();
	gob3.showStatus();
	gob3.castSpell();
	cout << endl;

	gob4.defend();
	gob4.attack();
	gob4.showStatus();
	cout << endl;
	gob4.castSpell();
	cout << endl;
	gob4.summonMinion();



	system("PAUSE");
	system("cls");
}
