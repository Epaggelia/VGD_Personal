#include <iostream>
#include <string>

using std::string;

#ifndef CHARACTER_H
#define CHARACTER_H

/*The character must be defined by the following traits: 
name 
race 
class
strength 
dexterity
constitution 
wisdom
intelligence 
charisma
*/
class Character
{
public:
	Character();
	string setName();
	string pickRace();
	string pickClass();
	int randStat();
	void display();

private:
	string _name;
	string _race;
	string _class;
	int _strength = 0;
	int _dexterity = 0;
	int _constitution = 0;
	int _wisdom = 0;
	int _intelligence = 0;
	int _charisma = 0;
};

#endif