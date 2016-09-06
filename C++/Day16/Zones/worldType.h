#ifndef WORLD_TYPE_H
#define WORLD_TYPE_H

#include "zoneType.h"
#include <string>
#include <map>

using std::string;
using std::map;

class WorldType
{
public:
	WorldType();
	~WorldType();

	bool addZone(string key, ZoneType* zone);
	string  showCurrentZone() const;
	void setPosition(ZoneType* zone);
	bool move(ZoneType::DIRECTIONS direction);


	ZoneType* operator[](string key);

private:
	ZoneType* _currentPosition;
	map<string, ZoneType*> _world;
};


#endif