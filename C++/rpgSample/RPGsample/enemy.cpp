#include "enemy.h"
#include <stdlib.h>

using std::rand;

Enemy::Enemy(string type, int level, int maxHealth, string name, unsigned int exp, unsigned int gold) :
Creature(type, level, maxHealth)
{
	_name = name;
	_exp = exp;
	_gold = gold;

	for (int i = 0; i < ItemType::COUNT; i++)
	{
		_equipment[i] = nullptr;
	}
}

Enemy::~Enemy()
{
	for (int i = 0; i < ItemType::COUNT; i++)
	{
		if (_equipment[i])
		{
			delete _equipment[i];
		}
	}
}

string Enemy::getName() const
{
	return _name;
}

unsigned int Enemy::getExp() const
{
	return _exp;
}

unsigned int Enemy::getGold() const
{
	return _gold;
}

void Enemy::setName(string name)
{
	_name = name;
}

void Enemy::setExp(unsigned int exp)
{
	_exp = exp;
}

void Enemy::setGold(unsigned int gold)
{
	_gold = gold;
}

void Enemy::equipItem(ItemType* item)
{
	unsigned int slot = item->getSlot();

	if (_equipment[slot])
		delete _equipment[slot];

	_equipment[slot] = item;
}

int Enemy::getItemEffect(int slot) const
{
	if (_equipment[slot])
	{
		return _equipment[slot]->getEffect();
	}

	return 0;
}

void Enemy::attack(Creature& creature)
{
	int defValue = 10 + creature.getItemEffect(ItemType::HEAD) + creature.getItemEffect(ItemType::CHEST);

	int attValue = (rand() % 20 + 1) + (_level / 2);
	int dmg = 0;
	cout << endl<< endl<<_name << " attacks!" << endl;
		cout << "Attack ROll: " << attValue << endl
			<< "vs. Defensive Value: " << defValue << endl;

	if (attValue >= defValue)
	{
		dmg = _level + getItemEffect(ItemType::RHAND);
		
		cout << endl << _name << " hits " << creature.getType()
			<< " with his ";
		if (_equipment[ItemType::RHAND] != nullptr)
		{
			cout << _equipment[ItemType::RHAND]->getDescription();
		}
		else
		{
			cout << "bare hands";
		}
		cout << " for " << dmg << " damage." << endl;
	}
	else
	{
		cout << endl << _name << " has missed." << endl;
	}

	creature.receiveDamage(dmg);
}

void Enemy::receiveDamage(unsigned int damage)
{
	_currHealth -= damage;

	if (_currHealth <= 0)
	{
		_currHealth = 0;
		_isAlive = false;
	}
}

void Enemy::listEquipment() const
{
	cout << endl << "Equipment" << endl;
	if (_equipment[ItemType::HEAD])
	{
		cout << "Head: " << _equipment[ItemType::HEAD]->getDescription()
			<< "\tDEF: " << _equipment[ItemType::HEAD]->getEffect() << endl;
	}
	else
	{
		cout << "Head: Nothing.\tDEF: 0" << endl;
	}

	if (_equipment[ItemType::CHEST])
	{
		cout << "Chest: " << _equipment[ItemType::CHEST]->getDescription()
			<< "\tDEF: " << _equipment[ItemType::CHEST]->getEffect() << endl;
	}
	else
	{
		cout << "Chest: Nothing.\tDEF: 0" << endl;
	}

	if (_equipment[ItemType::RHAND])
	{
		cout << "R-Hand: " << _equipment[ItemType::RHAND]->getDescription()
			<< "\tATK: " << _equipment[ItemType::RHAND]->getEffect() << endl;
	}
	else
	{
		cout << "R-Hand: Nothing.\tATK: 0" << endl;
	}

	if (_equipment[ItemType::LHAND])
	{
		cout << "L-Hand: " << _equipment[ItemType::LHAND]->getDescription()
			<< "\tATK: " << _equipment[ItemType::LHAND]->getEffect() << endl;
	}
	else
	{
		cout << "L-Hand: Nothing.\tATK: 0" << endl;
	}
}
void Enemy::displayCharacter()
{
	cout << endl << "Character sheet" << endl
		<< "Name: " << _name << "\tType: " << _type << endl
		<< "Level: " << _level << "\tExp: " << _exp << endl
		<< "Health: " << _currHealth << "/" << _maxHealth << "\tGold: " << _gold << endl;

	listEquipment();
}