#include "itemType.h"
#include <vector>

using std::vector;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
protected:
	vector<ItemType*> _inventory;
public:
	void addItem(ItemType* item);
	ItemType* dropItem(int index);
	void listItems();
	bool hasItems();
};


#endif