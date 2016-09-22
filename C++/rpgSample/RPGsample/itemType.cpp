#include "itemType.h"

ItemType::ItemType(string des, int slot, int effect)
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

	_effect = effect;
}

int ItemType::getSlot() const
{
	return _slot;
}

int ItemType::getEffect() const
{
	return _effect;
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

void ItemType::setEffect(int effect)
{
	_effect = effect;
}

void ItemType::setDescription(string des)
{
	_description = des;
}