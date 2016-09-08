#include "worldType.h"

WorldType::WorldType()
{

}

WorldType::~WorldType()
{
	map<string, ZoneType*>::iterator it = _world.begin();

	while (it != _world.end())
	{
		delete it->second;
		it++;
	}
}

bool WorldType::addZone(string key, ZoneType* zone)
{
	if (_world.find(key) != _world.end())
	{
		return false;
	}

	_world.insert(std::pair<string,ZoneType*>(key,zone));
	return true;
}

string WorldType::showCurrentZone() const
{
	return _currentPosition->_description;
}

void WorldType::setPosition(ZoneType* zone)
{
	if (zone!=nullptr)
	{
		_currentPosition = zone;
	}
}

bool WorldType::move(ZoneType::DIRECTIONS direction)
{
	if (_currentPosition !=nullptr)
	{
		if (_currentPosition->_exits[direction] != nullptr)
		{
			_currentPosition = _currentPosition->_exits[direction];
			return true;
		}
	}
	return false;
}

ZoneType* WorldType::operator[](string key)
{
	return _world[key];
}




