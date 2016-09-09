#ifndef ZONE_TYPE_H
#define ZONE_TYPE_H

#include <string>
#include <vector>
#include "itemType.h"

using std::string;
using std::vector;

class WorldType;

class ZoneType
{
public:
	friend class WorldType;

	enum DIRECTIONS{ NORTH, SOUTH, EAST, WEST, COUNT };

	ZoneType(string description = "A dark void.");
	~ZoneType() {}

	string getDescription() const;
	ZoneType* getExit(DIRECTIONS direction) const;

	void setDescription(string description);
	bool setExit(DIRECTIONS direction, ZoneType* zone);

	void removeExit(DIRECTIONS direction);

	void addItem(ItemType* item);
	ItemType* removeItem(int index);
	void listItems();
	bool hasItems();

private:
	string _description;
	ZoneType* _exits[COUNT];
	vector<ItemType*> _items;
};

#endif
