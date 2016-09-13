#include "player.h"
#include <iostream>

using std::find;
using std::cout;
using std::endl;

Player::Player(string type, int level, int maxHealth) : Creature(type, level, maxHealth)
{
	
}

void Player::addItem(ItemType* item)
{
	if (find(_inventory.begin(), _inventory.end(),item) != _inventory.end())
	{
		return;
	}

	_inventory.push_back(item);
}

ItemType* Player::dropItem(int index)
{
	if (index < 1 || index > _inventory.size())
	{
		return nullptr;
	}

	int zeroBased = index - 1;
	ItemType* item = _inventory.at(zeroBased);
	_inventory.erase(_inventory.begin() + zeroBased);

	return item;
}

void Player::listItems()
{
	cout << endl << "Inventory" << endl;
	if (_inventory.size() == 0)
	{
		cout << "  Nothing." << endl;
		return;
	}
	for (int i = 0; i < _inventory.size(); i++)
	{
		cout << "[" << i + 1 << "] " << _inventory[i]->getDescription() << endl;
	}
}

bool Player::hasItems()
{
	return _inventory.size() > 0;
}

void Player::displayCharacter()
{
	Creature::displayCharacter();

	listItems();
}