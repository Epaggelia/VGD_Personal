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

			talkToACritter(selectedCritter);
		}
		else if (userInput == 2)
		{
			Critter* selectedCritter = pickACritter(farm, CRITTER_COUNT);

			feedACritter(selectedCritter);
		}
		else if (userInput == 3)
		{
			Critter* selectedCritter = pickACritter(farm, CRITTER_COUNT);

			playWithACritter(selectedCritter);
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

void talkToACritter(const Critter* critter)
{
	if (critter != nullptr)
	{
		critter->talk();
	}
}

void feedACritter(Critter* critter)
{
	if (critter != nullptr)
	{
		do 
		{
			cout << endl << "What will you feed " << critter->getName() << "?" << endl;
			cout << "[1] Cupcake" << endl;
			cout << "[2] Pizza" << endl;
			cout << "[3] 3-course meal" << endl;
			cout << "[4] Return" << endl;
			cout << "> ";

			int userInput = getValidInt();

			if (userInput == 1)
			{
				critter->feed(1);
				break;
			}
			else if (userInput == 2)
			{
				critter->feed(3);
				critter->passtime(0, 2);
				break;
			}
			else if (userInput == 3)
			{
				critter->feed(5);
				critter->passtime(0, 4);
				break;
			}
			else if (userInput == 4)
			{
				break;
			}
			else
			{
				cout << endl << "That's not a valid option. Try again." << endl;
			}

		} while (true);
	}
}

void playWithACritter(Critter* critter)
{
	if (critter != nullptr)
	{
		do
		{
			cout << endl << "How will you entertain " << critter->getName() << "?" << endl;
			cout << "[1] Tell a joke" << endl;
			cout << "[2] Play catch" << endl;
			cout << "[3] Go to the park" << endl;
			cout << "[4] Return" << endl;
			cout << "> ";

			int userInput = getValidInt();

			if (userInput == 1)
			{
				critter->entertain(1);
				break;
			}
			else if (userInput == 2)
			{
				critter->entertain(3);
				critter->passtime(0, 2);
				break;
			}
			else if (userInput == 3)
			{
				critter->entertain(5);
				critter->passtime(0, 4);
				break;
			}
			else if (userInput == 4)
			{
				break;
			}
			else
			{
				cout << endl << "That's not a valid option. Try again." << endl;
			}

		} while (true);
	}
}















