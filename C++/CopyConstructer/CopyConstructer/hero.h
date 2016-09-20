#include "item.h"

#ifndef HERO_H
#define HERO_H

class Hero
{
public:
	Hero(Item* pItem = nullptr);
	Hero(const Hero& heroRef);
	~Hero();

	Item& getItem() const;
	void operator=(const Hero& heroRef);

private:
	Item* _pItem;
};


#endif