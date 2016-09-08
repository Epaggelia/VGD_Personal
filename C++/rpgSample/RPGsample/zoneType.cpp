#include <algorithm>
#include "zoneType.h"

using std::find;

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