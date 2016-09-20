#include "hero.h"

Hero::Hero(Item* pItem)
{
	_pItem = pItem;
}

Hero::~Hero()
{
	if (_pItem)
		delete _pItem;
}

Hero::Hero(const Hero& heroRef)
{
	string type = heroRef._pItem->getType();
	_pItem = new Item(type);
}



Item& Hero::getItem() const
{
	return (*_pItem);
}

void Hero::operator=(const Hero& heroRef)
{
	if (_pItem)
	{
		delete _pItem;
		_pItem = nullptr;
	}

	string type = heroRef._pItem->getType();
	_pItem = new Item(type);
}