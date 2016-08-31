#include <string>

using std::string;
#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

class ItemType
{
public:
	ItemType(string type = "Stick", int effect = 0);
	
	string getType() const;
	int getEffect() const;

	void setType(string type);
	void setEffect(int effect);
private:
	string _type;
	int _effect;
};

#endif