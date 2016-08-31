#include <iostream>
#include "creature.h"

using std::cout;
using std::endl;

Creature::Creature()
{
	_type = "Rat";
	_level = 1;
	_maxHealth = 1;
	_currentHealth = _maxHealth;
	_damage = 0;
	_defense = 0;
}

Creature::Creature(int health, int maxlevel, int damage, int defense, string type)
{
	_type = type;
	_maxHealth = health;
	_currentHealth = _maxHealth;
	_level = maxlevel;
	_damage = damage;
	_defense = defense;
}

void Creature::attack(Creature& other)
{
	other.receiveDamage(_damage);
}

void Creature::defend()
{
	cout << _type << " defends itself!" << endl;
}

void Creature::receiveDamage(int amount)
{
	defend();
	cout << _type << " takes " << amount << " damage." << endl;
}

string Creature::type()
{
	return _type;
}