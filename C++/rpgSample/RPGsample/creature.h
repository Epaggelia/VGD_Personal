#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Creature
{
protected:
	string _type;
	int _level;
	int _currHealth;
	int _maxHealth;
	
	bool _isAlive;
	
public:
	Creature(string type = "Rat", int level = 1, int maxHealth = 1) : 
		_type(type), _level(level), _currHealth(maxHealth), _maxHealth(maxHealth), _isAlive(true)
	{
	}
	virtual ~Creature() {}

//////////////

	string getType() const
	{
		return _type;
	}

	int getLevel() const
	{
		return _level;
	}

	int getCurrentHealth() const
	{
		return _currHealth;
	}

	bool isAlive() const
	{
		return _isAlive;
	}

//////////////

	void setType(string type)
	{
		_type = type;
	}

	void setLevel(int level)
	{
		_level = level;
	}

	void setCurrentHealth(int level)
	{
		_level = level;
	}

	virtual void displayCharacter()
	{
		cout << endl << "Character Sheet" << endl;
		cout << "Type: " << _type << endl;
		cout << "Level: " << _level << "\tHealth: " << _currHealth << "/" << _maxHealth << endl;
	}

private:

};


#endif