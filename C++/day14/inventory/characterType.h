#include "itemType.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::find;
using std::cout;
using std::cin;
using std::endl;

#ifndef CHARACTER_TYPE_H
#define CHARACTER_TYPE_H

class CharacterType
{
public:
	CharacterType();
	void showItem()const;
	void showEquipment()const;
	void carryItem(ItemType* item);
	bool equipItem(ItemType* item);

	ItemType* dropItem();

private:
	vector<ItemType*> _inventory;
	ItemType* _equipment[ItemType::COUNT];
};



#endif