#include <iostream>

using std::cout;
using std::endl;

#ifndef DATE_TYPE_H
#define DATE_TYPE_H

class DateType
{
public:
	DateType(int month = 1, int day = 1, int year = 1970);
	void printDate() const;
	void setDate(int month, int day, int year);
private:
	int _month;
	int _day;
	int _year;
};

#endif