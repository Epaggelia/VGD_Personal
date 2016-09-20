#include "item.h"

Item::Item(string type)
{
	_type = type;
}

string Item::getType() const
{
	return _type;
}

void Item::setType(string type)
{
	_type = type;
}

