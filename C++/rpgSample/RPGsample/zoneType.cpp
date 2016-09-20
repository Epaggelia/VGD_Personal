#include <algorithm>
#include <iostream>
#include "zoneType.h"

using std::find;
using std::cout;
using std::endl;


ZoneType::ZoneType(string description)
{
	_description = description;
	for (int i = 0; i < DIRECTIONS::COUNT; i++)
	{
		_exits[i] = nullptr;
	}
}

string ZoneType::getDescription() const
{
	return _description;
}

ZoneType* ZoneType::getExit(DIRECTIONS direction) const
{
	return _exits[direction];
}

void ZoneType::setDescription(string description)
{
	_description = description;
}

bool ZoneType::setExit(DIRECTIONS direction, ZoneType* zone)
{
	if (zone == nullptr || _exits[direction] != nullptr)
	{
		return false;
	}

	_exits[direction] = zone;
	return true;
}

void ZoneType::removeExit(DIRECTIONS direction)
{
	_exits[direction] = nullptr;
}

void ZoneType::addItem(ItemType* item)
{
	if (find(_items.begin(), _items.end(),item) != _items.end())
	{
		return;
	}

	_items.push_back(item);
}

ItemType* ZoneType::removeItem(int index)
{
	if (index < 1 || index > _items.size())
	{
		return nullptr;
	}

	int zeroBased = index - 1;
	ItemType* item = _items.at(zeroBased);
	_items.erase(_items.begin() + zeroBased);

	return item;
}
void ZoneType::listItems()
{
	for (int i = 0; i < _items.size(); i++)
	{
		cout << "[" << i + 1 << "] " << _items[i]->getDescription() << endl;
	}
}

bool ZoneType::hasItems()
{
	if (_items.size() > 0)
	{
		return true;
	}
	return false;
}

void ZoneType::addEnemy(Enemy* enemy)
{
	if (find(_enemies.begin(), _enemies.end(), enemy) != _enemies.end())
	{
		return;
	}

	_enemies.push_back(enemy);
}

Enemy* ZoneType::removeEnemy(int index)
{
	if (index < 1 || index > _enemies.size())
	{
		return nullptr;
	}

	int zeroBased = index - 1;
	Enemy* enemy = _enemies.at(zeroBased);
	_enemies.erase(_enemies.begin() + zeroBased);
	return enemy;
}

void ZoneType::listEnemies()
{
	for (int i = 0; i < _enemies.size(); i++)
	{
		cout << "[" << i + 1 << "] " << _enemies[i]->getType();
	}
}

bool ZoneType::hasEnemies()
{
	if (_enemies.size() > 0)
	{
		return true;
	}
	return false;
}