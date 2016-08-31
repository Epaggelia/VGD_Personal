#include "PersonType.h"
#include "DateType.h"


#ifndef PERSONAL_INFO_H
#define PERSONAL_INFO_H

class PersonalInfo
{
public:
	PersonalInfo(string first, string last, 
		int day = 1, int month = 1, int year = 1970, 
		int ID = 0);

	void print() const;

private:
	DateType _birthday;
	PersonType _person;
	int _ID;
};


#endif // !PERSONAL_INFO_H

