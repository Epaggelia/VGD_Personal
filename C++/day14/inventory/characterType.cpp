#include "characterType.h"

CharacterType::CharacterType()
{
	for (int i = 0; i < ItemType::COUNT; i++)
	{
		_equipment[i] = nullptr;
	}
}

void CharacterType::showItem()const
{
	cout << endl << "INVENTORY: " << endl;
	for (int i = 0; i < _inventory.size(); i++)
	{
		cout << _inventory[i]->getDescription() << endl;
	}
	cout << endl;
}

void CharacterType::showEquipment() const
{
	cout << endl << "EQUIPMENT: " << endl;
	cout << "Head: ";
	if (_equipment[ItemType::HEAD] != nullptr)
	{
		cout << _equipment[ItemType::HEAD]->getDescription() << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}

	cout << "Chest: ";
	if (_equipment[ItemType::CHEST] != nullptr)
	{
		cout << _equipment[ItemType::CHEST]->getDescription() << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}

	cout << "Left Hand: ";
	if (_equipment[ItemType::LHAND] != nullptr)
	{
		cout << _equipment[ItemType::LHAND]->getDescription() << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}

	cout << "Right Hand: ";
	if (_equipment[ItemType::RHAND] != nullptr)
	{
		cout << _equipment[ItemType::RHAND]->getDescription() << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}
}

void CharacterType::carryItem(ItemType* item)
{
	vector<ItemType*>::iterator it;

	it = find(_inventory.begin(), _inventory.end(), item);

	if (it == _inventory.end())
	{
		_inventory.push_back(item);
	}
	else
	{
		cout << endl << "Error! Item already in inventory." << endl;
	}
}

bool CharacterType::equipItem(ItemType* item)
{
	int slot = item->getSlot();

	if (_equipment[slot] == nullptr)
	{
		_equipment[slot] = item;
		return true;
	}

	return false;
}

ItemType* CharacterType::dropItem()
{
	if (_inventory.size() == 0)
	{
		cout << "Nothing to drop." << endl;
		return nullptr;
	}

	int userInput = -1;

	cout << endl << "What will you drop? (0 to cancel)" << endl;

	for (int i = 0; i < _inventory.size(); i++)
	{
		cout << "[" << i + 1 << "] " << _inventory[i]->getDescription() << endl;
	}
	cout << "> ";
	cin >> userInput;

	while (userInput < 0 || userInput > _inventory.size())
	{
		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024,'\n');
			cout << "Invalid option." << endl;
			continue;
		}

		if (userInput == 0)
		{
			return nullptr;
		}
		else if (userInput > 0 && userInput <= _inventory.size())
		{
			int index = userInput - 1;
			ItemType* item = _inventory.at(index);
			_inventory.erase(_inventory.begin() + index);
			return item;
		}
	}	
}