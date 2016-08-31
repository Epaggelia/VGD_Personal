#include "PersonalInfo.h"

PersonalInfo::PersonalInfo(string first, string last, int month, int day, int year, int ID) : _person(first, last), _birthday(month, day, year)
{
	_ID = ID;
}

void PersonalInfo::print() const
{
	_person.printPerson();
	
	cout << "'s birthday is on ";
	_birthday.printDate();
	cout << ". Their record ID is " << _ID << endl;
}



