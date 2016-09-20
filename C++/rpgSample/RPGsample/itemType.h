#include <string>

using std::string;

#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

class ItemType
{
public:
	ItemType(string des = "Garbage", int slot = -1);

	enum SLOTS{NOSLOT = -1,HEAD,CHEST,LHAND,RHAND,COUNT};

	int getSlot() const;
	int getEffect() const;
	string getDescription() const;

	void setSlot(int slot);
	void setEffect(int effect);
	void setDescription(string des);
	
private:
	string _description;
	int _slot;
	int _effect;
};

#endif