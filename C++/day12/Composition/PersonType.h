#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

class PersonType
{
public:
	PersonType(string first = "", string last = "");
	void printPerson() const;
	void setPerson(string first, string last);
private:
	string _firstName;
	string _lastName;
};



#endif 
