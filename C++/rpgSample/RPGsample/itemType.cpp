#include "itemType.h"

ItemType::ItemType(string des, int slot)
{
	_description = des;
	if (slot<= NOSLOT || slot >= COUNT)
	{
		_slot = NOSLOT;
	}
	else
	{
		_slot = slot;
	}
}

int ItemType::getSlot() const
{
	return _slot;
}

string ItemType::getDescription() const
{
	return _description;
}

void ItemType::setSlot(int slot)
{
	if (slot <= NOSLOT || slot >= COUNT)
	{
		_slot = NOSLOT;
	}
	else
	{
		_slot = slot;
	}
}

void ItemType::setDescription(string des)
{
	_description = des;
}