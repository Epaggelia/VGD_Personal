#include "GladiatorType.h"

GladiatorType::GladiatorType(string name, int health, ItemType& weapon, ItemType& armor) : _weapon(weapon), _armor(armor)
{
	_name = name;
	_maxHealth = health;
	_currentHealth = _maxHealth;
}

string GladiatorType::getName() const
{
	return _name;
}

int GladiatorType::getHealth() const
{
	return _currentHealth;
}

void GladiatorType::setName(string name)
{
	_name = name;
}

void GladiatorType::setHealth(int health)
{
	_currentHealth = (health < 0) ? 0 : (health > _maxHealth) ? _maxHealth : health;
}

int GladiatorType::getWeaponEffect()const
{
	return _weapon.getEffect();
}

int GladiatorType::getArmorEffect()const
{
	return _armor.getEffect();
}

bool GladiatorType::isAlive() const
{
	return (_currentHealth > 0);
}