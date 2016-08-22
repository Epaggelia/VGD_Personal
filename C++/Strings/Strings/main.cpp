#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string str1 = "Game Over!";
	string str2("Thanks for playing!");



	cout << str1 << " Length: " << str1.length() << endl;
	cout << str2 << " Length: " << str2.length() << endl;

	cout << str1[0] << endl;
	str1[0] = 'L';
	str1.erase(6,3);
	cout << str1 << " Length: " << str1.length() << endl;

	string first;
	string last;

	cout << "Please enter your first name: ";
	cin >> first;
	cout << "Please enter your last name: ";
	cin >> last;

	string fullName = first + " " + last;
	string fullNameBackwards = "";
	for (int i = fullName.length() - 1; i >= 0; i--)
	{
		fullNameBackwards += (fullName[i]);
	}
	fullNameBackwards.append("?");
	cout << "Hi, " << fullNameBackwards << endl;

	system("PAUSE");
	return 0;
}
