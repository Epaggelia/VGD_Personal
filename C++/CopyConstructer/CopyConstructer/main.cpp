#include <iostream>
#include "hero.h"

using std::cout;
using std::endl;

int main()
{
	Item* sword = new Item("Sword");
	Hero Jeff(sword);
	Hero Nickolas = Jeff;

	Jeff.getItem().setType("Axe");

	cout << Jeff.getItem().getType() << endl;
	cout << Nickolas.getItem().getType() << endl;


	system("pause");
	return 0;
}