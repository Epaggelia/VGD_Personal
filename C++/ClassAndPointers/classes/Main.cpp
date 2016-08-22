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
};

int main()
{
	ClockType myClock;
	ClockType otherClock = ClockType(213, 3542, 32);

	myClock.printTime();
	otherClock.printTime();

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
	_hr = hr;
	_min = min;
	_sec = sec;
}



