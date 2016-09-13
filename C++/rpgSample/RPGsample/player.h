#ifndef PLAYER_H
#define PLAYER_H

#include "itemType.h"
#include "creature.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Player : public Creature
{
protected:
	vector<ItemType*> _inventory;
public:
	Player(string _type = "Human", int _level = 1, int maxHealth = 50);

	void addItem(ItemType* item);
	ItemType* dropItem(int index);
	void listItems();
	bool hasItems();

	void displayCharacter();
};


#endif