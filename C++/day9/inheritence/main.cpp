#include <iostream>
#include "Goblin.h"
#include "Goblin_boss.h"
#include "Goblin_cheif.h"

using std::cout;
using std::endl;

int getRandom(int min, int max);

int main()
{
	Goblin gob1;
	cout << endl;
	Goblin gob2("Chad", 2, 18);
	cout << endl;
	GoblinBoss gob3;
	cout << endl;
	GoblinCheif gob4;
	cout << endl;

	gob1.attack();
	gob1.defend();
	gob1.showStatus();
	cout << endl;

	gob2.attack();
	gob2.defend();
	gob2.showStatus();
	cout << endl;

	gob3.attack();
	gob3.defend();
	gob3.showStatus();
	gob3.castSpell();
	cout << endl;

	gob4.defend();
	gob4.attack();
	gob4.showStatus();
	cout << endl;
	gob4.castSpell();
	cout << endl;
	gob4.summonMinion();



	system("PAUSE");
	system("cls");
	int row[9][9];

	//set numbers
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[i][j] = j + 1;
		}
	}

	//scramble
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			do
			{
				int roll = getRandom(0, 8 - j);
				int temp = row[i][j];

				if (i == 0)
				{
					row[i][j] = row[i][j + roll];
					row[i][j + roll] = temp;
					break;
				}
				else
				{
					bool test = true;
					for (int n = 0; n < i; n++)
					{
						if (row[n - 1][j] == row[i][j + roll])
						{
							test = false;
						}
					}

					if (test)
					{
						row[i][j] = row[i][j + roll];
						row[i][j + roll] = temp;
						break;
					}
				}
			} while (true);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << row[i][j];
			if ((j + 1) % 3 == 0)
				cout << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	system("cls");
}

int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}
