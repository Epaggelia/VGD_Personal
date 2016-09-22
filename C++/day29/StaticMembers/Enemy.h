#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy
{
public:
	Enemy();
	~Enemy();

	int getHealth();
	static void enemyCount();

private:
	int health;
	static int count;
};



#endif