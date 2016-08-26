#include <string>

using std::string;

#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin
{
protected:
	string _name;
	int _level;
	int _currentHealth, _maxHealth;

public:
	Goblin();
	Goblin(string name, int level, int health);

	virtual void attack();
	void defend();
	void showStatus();
 
};


#endif