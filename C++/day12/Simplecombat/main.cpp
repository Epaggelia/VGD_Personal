#include "GladiatorType.h"
#include "ItemType.h"

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using std::vector;
using std::srand;
using std::rand;
using std::cout;
using std::endl;

void battle(GladiatorType& g1, GladiatorType& g2);
void battleRoyal(vector<GladiatorType>& gladiators);
void makeGladiator(vector<GladiatorType>& gladiators);


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	GladiatorType maximus("Maximus", 30, ItemType("Gladius", 10), ItemType("Cuirass", 10));
	GladiatorType sparticus("Sparticus", 30, ItemType("Pilum", 10), ItemType("Lorica Segmentata", 10));

	vector<GladiatorType> gladiators;

	makeGladiator(gladiators);

	battleRoyal(gladiators);

	//battle(maximus, sparticus);

	system("PAUSE");
	return 0;
}

void battle(GladiatorType& g1, GladiatorType& g2)
{
	cout << "Battle begins!" << endl << endl;
	cout << g1.getName() << " vs. " << g2.getName() << endl << endl;

	do
	{
		cout << "HP:" << g1.getHealth() << "\t\t" << "HP: " << g2.getHealth() << endl << endl;
		cout << "WP:" << g1.getWeaponEffect() << "\t\t" << "WP: " << g2.getWeaponEffect() << endl << endl;
		cout << "AR:" << g1.getArmorEffect() << "\t\t" << "AR: " << g2.getArmorEffect() << endl << endl;

		int toss = rand() % 50 + 1;

		if (toss > 50)
		{
			int damage = g1.getWeaponEffect();
			int defense = g2.getArmorEffect() / 2;
			int health = g2.getHealth();

			cout << g1.getName() << " attacks for " << damage << endl;
			cout << g2.getName() << " armor blocks " << defense << " points!" << endl;
			g2.setHealth(health - (damage - defense));
		}
		else
		{
			int damage = g2.getWeaponEffect();
			int defense = g1.getArmorEffect() / 2;
			int health = g1.getHealth();

			cout << g2.getName() << " attacks for " << damage << endl;
			cout << g1.getName() << " armor blocks " << defense << " points!" << endl;
			g1.setHealth(health - (damage - defense));
		}

		system("PAUSE");
		system("PAUSE");

	} while (g1.isAlive() && g2.isAlive());

	if (g1.isAlive())
	{
		cout << g2.getName() << " is slain!" << endl;
	}
	else
	{
		cout << g1.getName() << " is slain!" << endl;
	}
}

void battleRoyal(vector<GladiatorType>& gladiators)
{
	cout << "Let the battle begin!" << endl;
	cout << "The Gladiators are:" << endl;
	for (size_t i = 0; i < gladiators.size(); i++)
	{
		cout << gladiators[i].getName() << " ";
	}

	cout << endl << endl;

	do
	{
		for (size_t i = 0; i < gladiators.size(); i+=2)
		{
			if (i + 1 < gladiators.size())
			{
				cout << gladiators[i].getName() << "\t\t" << gladiators[i + 1].getName() << endl;
				cout << "HP: " << gladiators[i].getHealth() << "\t\t" << "HP: " << gladiators[i + 1].getHealth() << endl;
				cout << "WP: " << gladiators[i].getWeaponEffect() << "\t\t" << "WP: " << gladiators[i + 1].getWeaponEffect() << endl;
				cout << "AR: " << gladiators[i].getArmorEffect() << "\t\t" << "AR: " << gladiators[i + 1].getArmorEffect() << endl;
			}
			else
			{
				cout << gladiators[i].getName() << endl;
				cout << "HP: "<< gladiators[i].getHealth() << endl;
				cout << "WP: "<< gladiators[i].getWeaponEffect() << endl;
				cout << "AR: "<< gladiators[i].getArmorEffect() << endl;
			}
		}

		int attacker = rand() % gladiators.size();
		int defender = -1;
		do
		{
			defender = rand() % gladiators.size();
		} while (defender == attacker);

		int damage = gladiators[attacker].getWeaponEffect();
		int defense = gladiators[defender].getArmorEffect()/2;
		int health = gladiators[defender].getHealth();

		cout << gladiators[attacker].getName() << " attacks " << gladiators[defender].getName() << " for " << damage << " damage!" << endl;
		cout << gladiators[defender].getName() << " blocks " <<	defense << " points of damage!" << endl;

		gladiators[defender].setHealth(health - (damage - defense));

		cout << endl;

		if (gladiators[defender].isAlive() == false)
		{
			cout << gladiators[defender].getName() << " is slain!" << endl << endl;
			gladiators.erase(gladiators.begin() + defender);
		}

		system("PAUSE");

	} while (gladiators.size() > 1);
	
	cout << gladiators[0].getName() << " is victorious!" << endl << endl;
}

void makeGladiator(vector<GladiatorType>& gladiators)
{
	gladiators.push_back(GladiatorType("Tetriat", 30, ItemType("Gladius", 10), ItemType("Sheild", 10)));
	gladiators.push_back(GladiatorType("Priscus", 30, ItemType("Trident", 10), ItemType("Helmet", 10)));
	gladiators.push_back(GladiatorType("Spicul", 30, ItemType("Pilum", 10), ItemType("Tower Sheild", 10)));
	gladiators.push_back(GladiatorType("Jeff", 30, ItemType("Kung Fu", 10), ItemType("Pajamas", 10)));
	gladiators.push_back(GladiatorType("Nick", 30, ItemType("Stick", 10), ItemType("Sarcasm", 10))); 
}

