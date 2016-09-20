#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item
{
public:
	Item(string type = "Stick");
	string getType() const;
	void setType(string type);

private:
	string _type;
};


#endif