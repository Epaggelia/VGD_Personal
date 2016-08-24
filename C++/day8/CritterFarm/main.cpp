#include <iostream>
#include"critter.h"

using std::cout;
using std::cin;
using std::endl;

void talkToACritter(const Critter *critter);
void feedACritter(Critter *critter);
void playWithACritter(Critter *critter);

Critter* pickACritter(Critter* farm[], int count);

const int CRITTER_COUNT = 3;

int getRandom(int min, int max);

int getValidInt()
{
	int userInput;

	if (!(cin >> userInput))
	{
		cin.clear();
		cin.ignore(1024, '\n');

		return -1;
	}
	return userInput;
}

int main()
{
	Critter *farm[CRITTER_COUNT];

	for (int i = 0; i < CRITTER_COUNT; i++)
	{
		cout << "Please give critter #" << i + 1 << " a name: ";
		string name;
		cin >> name;

		farm[i] = new Critter(name);
	}

	do
	{
		int userInput;
		string critterPicked;
		cout << "[1] Talk to a critter." << endl;
		cout << "[2] Feed a critter." << endl;
		cout << "[3] Entertain a critter." << endl;
		cout << "[4] Exit." << endl;
		userInput = getValidInt();

		if (userInput == 1)
		{
			Critter* selectedCritter = pickACritter(farm, CRITTER_COUNT);

			if (selectedCritter != nullptr)
			{
				selectedCritter->talk();
			}
		}
		else if (userInput == 2)
		{

		}
		else if (userInput == 3)
		{

		}
		else if (userInput == 9)
		{
			system("cls");
			int row[9][9];

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					row[i][j] = j + 1;
					cout << row[i][j];
					if ((j + 1) % 3 == 0)
						cout << " ";
				}
				cout << endl;
			}

			for (int i = 9; i >0; i--)
			{
				int roll = getRandom(0, i);
				cout << roll << " 0 --> " << i << endl;
			}




			system("PAUSE");	
			system("cls");
		}
		else
		{
			break;
		}

	} while (true);

	system("PAUSE");
	return 0;
}

Critter* pickACritter(Critter* farm[], int  count)
{
	cout << "Which critter will you select?" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << "[" << i + 1 << "] " << farm[i]->getName() << endl;
	}
	cout << "> ";

	int userInput = getValidInt();

	if (userInput > 0 && userInput <= count)
		return farm[userInput - 1];
	else
		return nullptr;
}


int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}














