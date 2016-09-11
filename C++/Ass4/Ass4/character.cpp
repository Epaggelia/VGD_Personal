#include <iostream>
#include "character.h"

using std::cout;
using std::cin;
using std::endl;

Character::Character()
{
	_name = setName();
	_strength += randStat();
	_dexterity += randStat();
	_constitution += randStat();
	_wisdom += randStat();
	_intelligence += randStat();
	_charisma += randStat();
	_race = pickRace();
	_class = pickClass();
	
}

string Character::setName()
{
	string name;
	cout << "Enter the name of your character:\n> ";
	cin >> name;
	cout << endl<< "Name Set." << endl;
	system("pause");
	system("cls");
	return name;
}

string Character::pickRace()
{
	int userInput;
	string race;
	do
	{
		cout << "Pick a race from the following list:" << endl;
		cout << "[1] Human\t" << "(No stat effect)" << endl;
		cout << "[2] Elf\t\t" << "(+1 WIS, +1 INT, -1 STR)" << endl;
		cout << "[3] Dwarf\t" << "(+1 CON, +1 STR, -1 INT)" << endl;
		cout << "[4] Halfling\t" << "(+1 DEX, +1 CHA, -1 CON)" << endl;
		cout << "[5] Gnome\t" << "(+2 DEX, -1 STR)" << endl;
		cout << "[6] Half-Orc\t" << "(+2 STR, -1 CHA)" << endl;
		cout << "> ";

		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid Input." << endl;
			system("pause");
			system("cls");
			continue;
		}

		if (userInput < 1 || userInput > 6)
		{
			cout << "Invalid Input." << endl;
			system("pause");
			system("cls");
			continue;
		}

		if (userInput == 1)
		{
			race = "Human";
			break;
		}
		else if (userInput==2)
		{
			race = "Elf";
			_wisdom += 1;
			_intelligence += 1;
			_strength += -1;
			break;
		}
		else if (userInput == 3)
		{
			race = "Dwarf";
			_constitution += 1;
			_strength += 1;
			_intelligence += -1;
			break;
		}
		else if (userInput == 4)
		{
			race = "Halfling";
			_dexterity += 1;
			_charisma += 1;
			_constitution += -1;
			break;
		}
		else if (userInput == 5)
		{
			race = "Gnome";
			_dexterity += 2;
			_strength += -1;
			break;
		}
		else if (userInput == 6)
		{
			race = "Half-Orc";
			_strength += 2;
			_charisma += -1;
			break;
		}

	} while (true);

	cout << endl << "Race Set." << endl;
	system("pause");
	system("cls");
	return race;
}

string Character::pickClass()
{
	int userInput;
	string charClass;

	do
	{
		cout << "Pick a class from the following list:" << endl;
		cout << "[1] Fighter" << endl;
		cout << "[2] Wizard" << endl;
		cout << "[3] Cleric" << endl;
		cout << "[4] Rogue" << endl;
		cout << "[5] Ranger" << endl;
		cout << "> ";

		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid Input." << endl;
			system("pause");
			system("cls");
			continue;
		}

		if (userInput < 1 || userInput > 5)
		{
			cout << "Invalid Input." << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (userInput == 1)
		{
			charClass = "Fighter";
			break;
		}
		else if (userInput == 2)
		{
			charClass = "Wizard";
			break;
		}
		else if (userInput == 3)
		{
			charClass = "Cleric";
			break;
		}
		else if (userInput == 4)
		{
			charClass = "Rogue";
			break;
		}
		else if (userInput == 5)
		{
			charClass = "Ranger";
			break;
		}
	} while (true);
	
	cout << endl << "Class Set." << endl;
	system("pause");
	system("cls");
	return charClass;
}

int Character::randStat()
{
	return 10 + ((rand() % 10) - 2);
}

void Character::display()
{
	cout << "Character Sheet:" << endl;
	cout << "Name: " << _name << endl;
	cout << "Race: " << _race << endl;
	cout << "Class: " << _class << endl;
	cout << "STR: " << _strength << "\t DEX: " << _dexterity << endl;
	cout << "CON: " << _constitution << "\t WIS: " << _wisdom << endl;
	cout << "INT: " << _intelligence << "\t CHA: " << _charisma << endl;
}