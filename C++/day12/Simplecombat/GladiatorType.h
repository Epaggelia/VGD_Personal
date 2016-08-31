#include "ItemType.h"

#ifndef GLADIATOR_TYPE_H
#define GLADIATOR_TYPE_H

class GladiatorType
{
public:
	GladiatorType(string name = "Frank", int health = 10, ItemType& weapon = ItemType("sword", 5),ItemType& armor = ItemType("Loincloth",2));

	string getName() const;
	int getHealth() const;

	void setName(string name);
	void setHealth(int health);

	int getWeaponEffect() const;
	int getArmorEffect() const;

	bool isAlive() const;


private:
	string _name;
	int _currentHealth;
	int _maxHealth;

	ItemType _weapon;
	ItemType _armor;
};

#endif // !GLADIATOR_TYPE_H
