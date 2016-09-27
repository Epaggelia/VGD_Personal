#include "player.h"
#include <iostream>

using std::find;
using std::cout;
using std::endl;

Player::Player(string type, int level, int maxHealth, string name, int exp, int gold) :
Enemy(type, level, maxHealth, name, exp, gold)
{
	_requiredExp = 2 * level * 100;
}

void Player::addItem(ItemType* item)
{
	if (find(_inventory.begin(), _inventory.end(), item) != _inventory.end())
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

void Player::listItems(bool equipmentOnly)
{
	if (equipmentOnly)
	{
		cout << endl << "Equipment" << endl;
		int index = 1;
		for (int i = 0; i < _inventory.size(); i++)
		{
			ItemType* temp = _inventory[i];
			if (temp->getSlot() != ItemType::NOSLOT)
			{
				cout << "[" << index << "]" << temp->getDescription() << endl;
				index++;
			}
		}
	}
	else
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

}

bool Player::hasItems()
{
	return _inventory.size() > 0;
}

void Player::equipItem(ItemType* item)
{
	int slot = item->getSlot();

	if (slot == ItemType::NOSLOT)
	{
		cout << "You cannot equip that. Placing it in your inventory." << endl;
		addItem(item);
		return;
	}

	if (_equipment[slot])
	{
		/*cout << "Remove the " << _equipment[slot]->getDescription() << "first." << endl;
		addItem(item);*/
		cout << "Removing " << _equipment[slot]->getDescription() << endl;
		addItem(_equipment[slot]);
	}

	cout << "Equiping " << item->getDescription() << endl;
	cout << "Done." << endl;
	_equipment[slot] = item;
}

void Player::unequipItem(int slot)
{
	if (slot < 0 || slot >= ItemType::COUNT)
	{
		cout << "Invalid slot." << endl;
		return;
	}

	if (_equipment[slot])
	{
		addItem(_equipment[slot]);
		cout << "Placing " << _equipment[slot]->getDescription() << " in you inventory." << endl;
		_equipment[slot] = nullptr;
		cout << "Done." << endl;
	}
	else
	{
		cout << "You have nothing equipped in that slot." << endl;
	}
}

bool Player::hasEquipment() const
{
	return (_equipment[ItemType::HEAD] ||
		_equipment[ItemType::CHEST] ||
		_equipment[ItemType::LHAND] ||
		_equipment[ItemType::RHAND]);
}

ItemType* Player::findEquipment(int index)
{
	if (index < 1 || index > _inventory.size())
	{
		cout << "Invalid option." << endl;
		return nullptr;
	}

	int temp = 1;
	for (int i = 0; i < _inventory.size(); i++)
	{
		if (_inventory[i]->getSlot() != ItemType::NOSLOT)
		{
			if (temp = index)
			{
				ItemType* temp = _inventory[i];
				_inventory.erase(_inventory.begin() + i);
				return temp;
			}
			temp++;
		}
	}
}

void Player::displayCharacter()
{
	Enemy::displayCharacter();

	listItems();
}