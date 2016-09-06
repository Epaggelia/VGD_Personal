#ifndef ZONE_TYPE_H
#define ZONE_TYPE_H

#include <string>

using std::string;

class WorldType;

class ZoneType
{
public:
	friend class WorldType;

	enum DIRECTIONS{ NORTH, SOUTH, EAST, WEST, COUNT };

	ZoneType(string description = "A dark void.");
	~ZoneType() {}

	string getDescription() const;
	ZoneType* getExit(DIRECTIONS direction) const;

	void setDescription(string description);
	bool setExit(DIRECTIONS direction, ZoneType* zone);

	void removeExit(DIRECTIONS direction);

private:
	string _description;
	ZoneType* _exits[COUNT];
};

#endif
