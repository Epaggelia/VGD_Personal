#include <iostream>

using std::cout;
using  std::endl;

class ClockType
{
	int _sec;
	int _min;
	int _hr;

public:
	ClockType();
	ClockType(int hr, int min, int sec);

	void printTime() const;
	void setTimer(int hr, int  min, int sec);
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
};

int main()
{
	ClockType myClock;
	ClockType otherClock = ClockType(213, 3542, 32);

	myClock.printTime();
	otherClock.printTime();

	myClock.setTimer(12, 59, 55);
	myClock.printTime();

	system("PAUSE");
	return 0;
}

ClockType::ClockType()
{
	_hr = 12;
	_min = 0;
	_sec = 0;
}

ClockType::ClockType(int hr, int min, int sec)
{
	_hr = hr % 24;
	_min = min % 60;
	_sec = sec % 60;
}

void ClockType::printTime() const
{
	cout << _hr << ":";

	if (_min < 10)
	{
		cout << "0";
	}
	cout << _min << ":";

	if (_sec < 10)
	{
		cout << "0";
	}
	cout << _sec << endl;
}

void ClockType::setTimer(int hr, int  min, int sec)
{
	if (sec >= 0)
	{
		_sec = sec % 60;
		min += sec / 60;
	}
	else
		_sec = 0;

	if (min >= 0)
	{
		_min = min % 60;
		hr += min / 60;
	}
	else
		_min = 0;

	if (hr > 0 && hr < 12)
		_hr = hr % 12;
	else
		_hr = 12;
}

void ClockType::incrementSeconds()
{
	_sec += 1;

	if (_sec >= 60)
	{
		_sec -= 60;
		incrementMinutes();
	}
}

void ClockType::incrementMinutes()
{
	_min += 1;

	if (_min >= 60)
	{
		_min -= 60;
		incrementHours();
	}
}

void ClockType::incrementHours()
{
	_hr += 1;
	
	if (_hr > 12)
		_hr -= 12;
}




