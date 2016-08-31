#include "PersonType.h"

PersonType::PersonType(string first, string last)
{
	_firstName = first;
	_lastName = last;
}

void PersonType::printPerson() const
{
	cout << _firstName << " " << _lastName;
}

void PersonType::setPerson(string first, string last)
{
	_firstName = first;
	_lastName = last;
}





















