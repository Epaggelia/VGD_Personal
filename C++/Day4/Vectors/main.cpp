#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	vector<string> gameList;

	gameList.push_back("Castlevania");
	gameList.push_back("Team Fortress 2");
	gameList.push_back("Diablo 3");
	gameList.push_back("Doom");
	gameList.push_back("Doom");

	gameList.pop_back();

	for (int i = 0; i < gameList.size(); i++)
	{
		cout << gameList.at(i) << endl;
	}

	vector<string>::iterator myIter;
	myIter = gameList.begin();

	for (/* blank */; myIter != gameList.end(); myIter++)
	{
		cout << *myIter << endl;
	}

	system("PAUSE");
	return 0;
}