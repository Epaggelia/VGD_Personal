#include "itemType.h"
#include "characterType.h"

#include <iostream>

using std::cout;
using std::endl;

void showGroundItems(const vector<ItemType*>& ground);

int main()
{
	ItemType *helment = new ItemType("Rusty Helmet", ItemType::HEAD);
	ItemType *chest = new ItemType("Dirty Shirt", ItemType::CHEST);
	ItemType *lHand = new ItemType("Dented Shield", ItemType::LHAND);
	ItemType *rHand = new ItemType("Bent Sword", ItemType::RHAND);

	CharacterType hero;

	vector<ItemType*> ground;

	hero.equipItem(helment);
	hero.carryItem(chest);
	hero.carryItem(lHand);
	hero.carryItem(rHand);

	int userInput;

	do
	{
		cout << "[1] Inventory" << endl;
		cout << "[2] Equipment" << endl;
		cout << "[3] Drop Item" << endl;
		cout << "[4] Check Ground" << endl;
		cout << "[0] Cancel" << endl;

		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Invalid option." << endl;
			continue;
		}

		if (userInput == 1)
		{
			hero.showItem();
		}
		else if (userInput == 2)
		{
			hero.showEquipment();
		}
		else if (userInput == 3)
		{
			ItemType* dropped = hero.dropItem();
			if (dropped != nullptr)
			{
				ground.push_back(dropped);
			}
		}
		else if (userInput == 4)
		{
			showGroundItems(ground);
		}
		else if (userInput == 0)
		{
			break;
		}

		cout << endl;
		system("pause");
		system("cls");
		
		
	} while (true);



	system("PAUSE");
	return 0;
}

void showGroundItems(const vector<ItemType*>& ground)
{
	cout << "Items on ground: " << endl;

	if (ground.size() == 0)
	{
		cout << "Nothing." << endl;
	}
	else
	{
		for (int i = 0; i < ground.size(); i++)
		{
			cout << ground[i]->getDescription() << endl;
		}
	}
}
