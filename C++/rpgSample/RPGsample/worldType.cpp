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

	_world["ARMORY"]->addItem(new ItemType("Crossbow", ItemType::RHAND, 7));
	_world["ARMORY"]->addItem(new ItemType("Chainmail coif", ItemType::HEAD, 3));

	_world["ROOM"]->addEnemy(new Enemy());

	_currentPosition = _world["CELL"];

	_player = new Player();
	_player->equipItem(new ItemType("Rock", ItemType::LHAND, 3));
	_player->equipItem(new ItemType("Rags", ItemType::CHEST, 1));
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

	cout << endl << "What would you like to do? ";

	if (_currentPosition->hasEnemies())
	{
		cout << "[A]ttack ";
	}
	else
	{
		cout << "[M]ove ";
	}

	if (_player->hasItems() || _player->hasEquipment())
	{
		cout << "[E]quipment ";
	}
		
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
	case 'A':
		if (_currentPosition->hasEnemies())
		{
			attack();
		}
		else
		{
			cout << "Nothing to attack." << endl;
		}
		break;
	case 'M':
		if (_currentPosition->hasEnemies() == false)
		{
			move();
		}
		else
		{
			cout << "You can't move right now." << endl;
		}
		break;
	case 'E':
		if (_player->hasItems() || _player->hasEquipment())
		{
			equip();
		}
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

void WorldType::attack()
{
	int choice = -1;

	cout << endl << "Which enemy would you like to attack." << endl;
	_currentPosition->listEnemies();
	cout << "> ";

	if (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(UINT_MAX, '\n');
		cout << "Invalid option." << endl;
	}
	else
	{
		Enemy* temp = _currentPosition->removeEnemy(choice);

		if (temp == nullptr)
		{
			cout << "Invalid option." << endl;
		}
		else
		{
			battle(temp);
			delete temp;
		}
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

void WorldType::equip()
{
	char choice = '~';

	cout << endl << "Equip a thing?" << endl;

	if (_player->hasItems())
		cout << "[E]quip ";

	if (_player->hasEquipment())
		cout << "[U]nequip ";

	cout << endl << "> ";

	cin >> choice;
	choice = toupper(choice);

	ItemType* item;
	int index = -1;
	switch (choice)
	{
	case 'E':
		cout << "Equp a thing?" << endl;
		_player->listItems(true);

		if (!(cin >> index))
		{
			cout << "meh" << endl;
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
		}
		else
		{
			item = _player->findEquipment(index);
			if (item != nullptr)
				_player->equipItem(item);
			else
				cout << "meh" << endl;
		}

		break;
	case 'U':
		cout << "Take it off." << endl <<
			"[H]ead, [C]hest, [L]eft hand, [R]ight hand?" << endl << endl;

		_player->listEquipment();

		cout << endl << endl << "> ";
		cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{
		case 'H':
			_player->unequipItem(ItemType::HEAD);
			break;
		case 'C':
			_player->unequipItem(ItemType::CHEST);
			break;
		case 'L':
			_player->unequipItem(ItemType::LHAND);
			break;
		case 'R':
			_player->unequipItem(ItemType::RHAND);
			break;
		}
		break;
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

	if (_currentPosition->hasEnemies())
	{
		cout << endl << "Enemies nearby: " << endl;
		_currentPosition->listEnemies();
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

void WorldType::battle(Enemy* enemy)
{
	do
	{
		int diceRoll = rand() % 100 + 1;

		if (diceRoll > 50)
		{
			_player->attack(*enemy);
		}
		else
		{
			enemy->attack(*_player);
		}

		_sleep(2000);

	} while (enemy->isAlive() && _player->isAlive());
}


