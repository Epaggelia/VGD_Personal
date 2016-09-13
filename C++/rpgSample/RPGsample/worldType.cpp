#include "worldType.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


WorldType::WorldType() :
_currentPosition(nullptr),
_player(nullptr)
{
	init();
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

void WorldType::init()
{		///////////////////////////////////////////////////////////////////////////////
	addZone("CELL", new ZoneType(
		"You are in a dark and moldy prision cell. The gate to your cell stands\n"
		"slightly ajar."));
	addZone("HALL", new ZoneType(
		"You are standing in corridor outside your cell. At your feet lies the guard\n"
		"who normally stands watch. He appears to be dead."));
	addZone("ROOM", new ZoneType(
		"You are standing in the guard room. The walls are splattered with blood, \n"
		"and the funiture has been smashed.\n"
		"There is no one here."));
	addZone("ARMORY", new ZoneType(
		"You are in armory. Most of the shelves and racks stand bare. You get the\n"
		"feeling you are being watched."));

	_world["CELL"]->setExit(ZoneType::DIRECTIONS::NORTH, _world["HALL"]);

	_world["HALL"]->setExit(ZoneType::DIRECTIONS::SOUTH, _world["CELL"]);
	_world["HALL"]->setExit(ZoneType::DIRECTIONS::WEST, _world["ROOM"]);

	_world["ROOM"]->setExit(ZoneType::DIRECTIONS::EAST, _world["HALL"]);
	_world["ROOM"]->setExit(ZoneType::DIRECTIONS::NORTH, _world["ARMORY"]);

	_world["ARMORY"]->setExit(ZoneType::DIRECTIONS::SOUTH, _world["ROOM"]);

	_world["ARMORY"]->addItem(new ItemType("Crossbow", ItemType::RHAND));
	_world["ARMORY"]->addItem(new ItemType("Chainmail coif", ItemType::HEAD));

	_currentPosition = _world["CELL"];

	_player = new Player();
}

bool WorldType::running()
{
	showCurrentZone();

	if (queryAction() == 'Q')
	{
		return false;
	}

	return true;
}

char WorldType::queryAction()
{
	char choice = '~';

	cout << endl << "What would you like to do? [M]ove ";

	if (_currentPosition->hasItems())
	{
		cout << "[T]ake ";
	}

	if (_player->hasItems())
	{
		cout << "[D]rop ";
	}

	cout << "[S]tats [Q]uit" << endl;
	cout << "> ";
	cin >> choice;

	choice = toupper(choice);

	switch (choice)
	{
	case 'M':
		move();
		break;
	case 'T':
		if (_currentPosition->hasItems())
		{
			take();
		}
		else
		{
			cout << "Nothing to take." << endl;
		}
		break;
	case 'D':
		if (_player->hasItems())
		{
			drop();
		}
		else
		{
			cout << "You have nothing to drop." << endl;
		}
		break;
	case 'S':
		_player->displayCharacter();
		break;
	case 'Q':
		return choice;
	default:
		cout << "I don't understand." << endl;
	}

}

void WorldType::move()
{
	char choice = '~';

	cout << endl << "Which way would you like to go? [C]ancel" << endl;
	cout << "> ";
	cin >> choice;

	choice = toupper(choice);
	switch (choice)
	{
	case 'N':
		if (move(ZoneType::DIRECTIONS::NORTH) == false)
			cout << endl << "You can't go that way." << endl;
		break;
	case 'E':
		if (move(ZoneType::DIRECTIONS::EAST) == false)
			cout << endl << "You can't go that way." << endl;
		break;
	case 'S':
		if (move(ZoneType::DIRECTIONS::SOUTH) == false)
			cout << endl << "You can't go that way." << endl;
		break;
	case 'W':
		if (move(ZoneType::DIRECTIONS::WEST) == false)
			cout << endl << "You can't go that way." << endl;
		break;
	case 'C':
		break;
	default:
		cout << "I don't understand." << endl;
	}
}

void WorldType::take()
{
	int choice = -1;
	cout << endl << "What would you like to take?" << endl;
	_currentPosition->listItems();
	cout << "> ";

	if (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(UINT_MAX, '\n');
		cout << "Invalid option." << endl;
	}
	else
	{
		ItemType* temp = _currentPosition->removeItem(choice);

		if (temp == nullptr)
		{
			cout << "Invalid option." << endl;
		}
		else
		{
			_player->addItem(temp);
			cout << "Taken." << endl;
		}
	}
}

void WorldType::drop()
{
	int choice = -1;
	cout << endl << "What would you like to drop?" << endl;
	_player->listItems();
	cout << "> ";

	if (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(UINT_MAX, '\n');
		cout << "Invalid option." << endl;
	}
	else
	{
		ItemType* temp = _player->dropItem(choice);

		if (temp == nullptr)
		{
			cout << "Invalid option." << endl;
		}
		else
		{
			_currentPosition->addItem(temp);
			cout << "Dropped." << endl;
		}
	}
}

void WorldType::showCurrentZone()
{
	cout << endl << _currentPosition->getDescription() << endl;

	if (_currentPosition->hasItems())
	{
		cout << endl << "Items nearby: " << endl;
		_currentPosition->listItems();
	}
}

bool WorldType::addZone(string key, ZoneType* zone)
{
	if (_world.find(key) != _world.end())
	{
		return false;
	}

	_world.insert(std::pair<string, ZoneType*>(key, zone));
	return true;
}

string WorldType::showCurrentZone() const
{
	return _currentPosition->_description;
}

void WorldType::setPosition(ZoneType* zone)
{
	if (zone != nullptr)
	{
		_currentPosition = zone;
	}
}

bool WorldType::move(ZoneType::DIRECTIONS direction)
{
	if (_currentPosition != nullptr)
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




