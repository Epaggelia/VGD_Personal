#include <iostream>
#include "zoneType.h"
#include "worldType.h"

using std::cout;
using std::endl;
using std::cin;

void buildWorld(WorldType& world);
void changePosition(ZoneType::DIRECTIONS whichway, WorldType& world);

int main()
{
	WorldType dungeon;
	buildWorld (dungeon);

	char choice = 'q';

	do
	{
		cout << endl << dungeon.showCurrentZone() << endl << endl;
		cout << "which way would you like to go? ";
		cin >> choice;

		switch (choice)
		{
		case 'n':
		case 'N':
			changePosition(ZoneType::NORTH, dungeon);
			break;
		case 'e':
		case 'E':
			changePosition(ZoneType::EAST, dungeon);
			break;
		case 's':
		case 'S':
			changePosition(ZoneType::SOUTH, dungeon);
			break;
		case 'w':
		case 'W':
			changePosition(ZoneType::WEST, dungeon);
			break;
		}
	} while (choice!= 'q');

	return 0;
}

void buildWorld(WorldType& world)
{
	world.addZone("GROOM", new ZoneType("A gaurd room."));
	world.addZone("HALL", new ZoneType("A dark hallway."));
	world.addZone("DEND", new ZoneType("A dead end. It looks like a storage room."));
	world.addZone("CELL", new ZoneType("A dirty cell."));
	world.addZone("COURTYARD", new ZoneType("A courtyard."));

	world["CELL"]->setExit(ZoneType::NORTH, world["HALL"]);
	world["HALL"]->setExit(ZoneType::SOUTH, world["CELL"]);
	world["HALL"]->setExit(ZoneType::EAST, world["DEND"]);
	world["HALL"]->setExit(ZoneType::WEST, world["GROOM"]);
	world["DEND"]->setExit(ZoneType::WEST, world["HALL"]);
	world["GROOM"]->setExit(ZoneType::EAST, world["HALL"]);
	world["GROOM"]->setExit(ZoneType::WEST, world["COURTYARD"]);
	world["COURTYARD"]->setExit(ZoneType::EAST, world["GROOM"]);

	world.setPosition(world["CELL"]);
}

void changePosition(ZoneType::DIRECTIONS whichWay, WorldType& world)
{
	if (world.move(whichWay) == false)
	{
		cout << "You can't go that way!" << endl;
	}
}

