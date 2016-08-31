#include <string>

using std::string;

#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
protected:
	string _type;
	int _currentHealth, _maxHealth;
	int _level;
	int _damage;
	int _defense;
public:
	Creature();
	Creature( int health,int maxlevel,int damage,int defense, string type);

	void attack(Creature& other);
	void defend();

	void receiveDamage(int amount);

	string type();

	virtual void castSpell() = 0;
	virtual void heal(Creature& other) = 0;

};

#endif