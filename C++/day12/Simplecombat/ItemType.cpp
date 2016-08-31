#include "ItemType.h"

ItemType::ItemType(string type, int effect)
{
	_type = type;
	_effect = effect;
}

string ItemType::getType() const
{
	return _type;
}

int ItemType::getEffect() const
{
	return _effect;
}

void ItemType::setType(string type)
{
	_type = type;
}

void ItemType::setEffect(int effect)
{
	_effect = effect;
}