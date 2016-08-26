#include <iostream>
#include <string>
#include <ctime>
#include "Goblin.h"
#include "Goblin_boss.h"
#include "Goblin_cheif.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;
using std::srand;
using std::time;

void makeGobAttack(Goblin& gob);

int getRandom(int min, int max);
void cardSort(int arr[], int n);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Goblin goblin;
	Goblin goblin2("Todd", 2, 20);
	GoblinBoss boss;
	GoblinBoss boss2("Barry", 5, 50, 5);
	GoblinCheif cheif;

	Goblin* gobbies[5];

	gobbies[0] = &goblin;
	gobbies[1] = &goblin2;
	gobbies[2] = &boss;
	gobbies[3] = &boss2;
	gobbies[4] = &cheif;

	for (int i = 0; i < 5; i++)
	{
		makeGobAttack(*gobbies[i]);
	}

	//Goblin& gob_ref = cheif;

	//gob_ref.attack();

	cout << endl;
	system("PAUSE");
	system("cls");

	////////////////////////////////////////////////////////////////////////////////////////////
	//suduku
	////////////////////////////////////////////////////////////////////////////////////////////
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
				int roll = getRandom(0, 8);
				int temp = row[i][j];

				if (i == 0)
				{
					row[i][j] = row[i][roll];
					row[i][roll] = temp;
					break;
				}
				else
				{
					bool test = true;

					for (int n = 0; n < i; n++)
					{
						if (row[n - 1][j] == row[i][roll])
						{
							test = false;
						}
					}

					if (test)
					{
						row[i][j] = row[i][roll];
						row[i][roll] = temp;
						break;
					}
				}
			} while (true);
		}
	}

	cout << endl;
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

	////////////////////////////////////////////////////////////////////////////////////////////
	// card stuff
	////////////////////////////////////////////////////////////////////////////////////////////
	int deck[52];
	string value[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string suit[4] = { "H", "C", "D", "S" };

	for (int i = 0; i < 52; i++)
	{
		deck[i] = i + 1;
		cout << deck[i] << " ";
		if ((i + 1) % 13 == 0)
			cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 52; i++)
	{
		int temp = deck[i];
		int roll = rand() % 52;
		deck[i] = deck[roll];
		deck[roll] = temp;

		cout << deck[i] << " ";
		if ((i + 1) % 13 == 0)
			cout << endl;
	}

	cout << endl;

	int hand[5] = { deck[0], deck[1], deck[2], deck[3], deck[4] };

	cardSort(hand, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << hand[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << value[hand[i] % 13] << suit[hand[i] / 13] << " ";
	}

	cout << endl;

	cardSort(deck, 52);

	for (int i = 0; i < 52; i++)
	{
		cout << value[deck[i] % 13] << suit[deck[i] / 13] << " ";
	}

	cout << endl;

	system("PAUSE");
	system("cls");
	return 0;
}

void makeGobAttack(Goblin& gob)
{
	gob.attack();
}



int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}

void cardSort(int arr[], int n)
{
	bool swapped = true;
	int j = 0;
	int tmp;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < n - j; i++)
		{
			if (arr[i] % 13 > arr[i + 1] % 13) 
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}
