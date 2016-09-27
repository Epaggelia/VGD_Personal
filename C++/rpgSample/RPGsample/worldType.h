#ifndef WORLD_TYPE_H
#define WORLD_TYPE_H

#include "zoneType.h"
#include "itemType.h"
#include "player.h"
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

	void init();
	bool running();
	char queryAction();
	void showCurrentZone();

	//player actions
	void attack();
	void move();
	void equip();
	void unequip();
	void take();
	void drop();

	void battle(Enemy* enemy);

private:
	ZoneType* _currentPosition;
	map<string, ZoneType*> _world;
	Player* _player;
};


#endif