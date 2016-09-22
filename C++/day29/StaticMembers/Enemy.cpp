#include <iostream>
#include "Enemy.h"

using std::cout;
using std::endl;

int Enemy::count = 0;

Enemy::Enemy()
{
	health = 100;
	count += 1;
}

Enemy::~Enemy()
{
	count -= 1;
}

void Enemy::enemyCount()
{
	cout << "You have ";
	if (Enemy::count == 0)
		cout << "no";
	else
		cout << Enemy::count;
	cout << " enem" << ((Enemy::count == 1) ? "y" : "ies") << "." << endl;
}

int Enemy::getHealth()
{
	return health;
}