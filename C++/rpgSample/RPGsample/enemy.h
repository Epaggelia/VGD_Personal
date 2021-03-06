#ifndef	ENEMY_H
#define ENEMY_H

#include "creature.h"
#include "itemType.h"

#include <string>

using std::string;
class Enemy : public Creature
{
protected:
	string _name;
	unsigned int _exp;
	unsigned int _gold;

	ItemType *_equipment[ItemType::SLOTS::COUNT];
public:
	Enemy(string type = "Goblin",
		int level = 1,
		int maxHealth = 15,
		string name = "George",
		unsigned int exp = 10,
		unsigned int gold = 5);
	~Enemy();

	string getName() const;
	unsigned int getExp() const;
	unsigned int getGold() const;

	void setName(string name);
	void setExp(unsigned int exp);
	void setGold(unsigned int gold);

	virtual void equipItem(ItemType* item);
	virtual int getItemEffect(int slot) const;
	void listEquipment() const;

	virtual void attack(Creature& creature);
	virtual void receiveDamage(unsigned int damage);

	void displayCharacter();

	private:

};



#endif
