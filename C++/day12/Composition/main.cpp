#include "PersonalInfo.h"

int main()
{
	int id = 0;

	PersonalInfo record1("Jeff", "Gauvin", 3, 27, 1982, ++id);
	PersonalInfo record2("Leonard", "Nimoy", 3, 26, 1931, ++id);
	PersonalInfo record3("Elton", "John", 3, 25, 1947, ++id);

	record1.print();
	record2.print();
	record3.print();


	system("PAUSE");
	return 0;
}

