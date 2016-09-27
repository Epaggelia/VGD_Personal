#ifndef PLAYER_H
#define PLAYER_H

#include "itemType.h"
#include "enemy.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Player : public Enemy
{
protected:
	vector<ItemType*> _inventory;
	unsigned int _requiredExp;
public:
	Player(string _type = "Human", int _level = 1, int maxHealth = 50,
		string name = "Jeff",
		int exp = 0,
		int gold = 0);

	void addItem(ItemType* item);
	ItemType* dropItem(int index);
	void listItems(bool equipmentOnly = false);
	bool hasItems();

	void equipItem(ItemType* item);
	void unequipItem(int slot);
	bool hasEquipment() const;
	ItemType* findEquipment(int index);
	
	void displayCharacter();

	int getItemEffect(int slot) const { return 0; };
};


#endif