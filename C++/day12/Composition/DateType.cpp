#include "DateType.h"

DateType::DateType(int month, int day, int year)
{
	_month = (month <1 || month > 12) ? 1 : month;
	
	_day = (day < 1 || day) > 31 ? 1 : day;

	_year = (year < 1900 || 3000) ? 1970 : year;
}

void DateType::printDate() const
{
	cout << _day << "/" << _month << "/" << _year;
}

void DateType::setDate(int month, int day, int year)
{
	_month = (month <1 || month > 12) ? 1 : month;

	_day = (day < 1 || day) > 31 ? 1 : day;

	_year = (year < 1900 || 3000) ? 1970 : year;
}





















