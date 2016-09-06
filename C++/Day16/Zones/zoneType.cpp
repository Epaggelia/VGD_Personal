#include "zoneType.h"

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