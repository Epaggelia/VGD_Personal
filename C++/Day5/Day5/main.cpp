#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::sort;
using std::string;
using std::vector;
using std::getline;

void viewList(const vector<string>& ref_list);
void addGame(vector<string>& ref_list);
void removeGame(vector<string>& ref_list);

int main()
{
	vector<string> gameList;

	bool quit = false;
	enum OPTIONS{ VIEW = 1, ADD, REMOVE, QUIT };

	do
	{
		int userSelection = 0;
		cout << "\tVideo Game List Manager - Hyper Rainbow Edition" << endl;
		do
		{
			cout << "[1] View current list." << endl;
			cout << "[2] Add a game title." << endl;
			cout << "[3] Remove a game title." << endl;
			cout << "[4] Quit." << endl;
			cout << "  > ";
			cin >> userSelection;

			if (userSelection < 1 || userSelection > 4)
			{
				cout << endl << "Please enter an option between 1 and 4." << endl << endl;
			}

		} while (userSelection < 1 || userSelection > 4);

		if (userSelection == VIEW)
		{
			viewList(gameList);
		}

		else if (userSelection == ADD)
		{
			addGame(gameList);
		}
		else if (userSelection == REMOVE)
		{
			removeGame(gameList);
		}
		else if (userSelection == QUIT)
		{

			quit = true;
		}

	} while (!quit);

	system("PAUSE");
	return 0;
}

void viewList(const vector<string> & ref_list)
{
	vector<string>::const_iterator iter;

	iter = ref_list.begin();

	cout << "\tCurrent List: " << endl << endl;
	if (ref_list.empty())
	{
		cout << "\t\t EMPTY" << endl;
	}
	else
	{
		for (/**/; iter != ref_list.end(); iter++)
		{
			cout << "\t\t" << *iter << endl;
		}
	}
	cout << endl;
}

void addGame(vector<string>& ref_list)
{
	string gameTitle;

	vector<string>::iterator iter;

	cout << "Enter a game name: " << endl;
	cin.ignore(1024, '\n');
	getline(cin, gameTitle);

	iter = find(ref_list.begin(), ref_list.end(), gameTitle);

	if (iter != ref_list.end())
	{
		cout << endl << "\t TITLE ALREADY EXISTS." << endl;
	}
	else{
		ref_list.push_back(gameTitle);
		cout << endl << "\t " << gameTitle << " added." << endl;
		sort(ref_list.begin(), ref_list.end());
	}
	cout << endl;
}

void removeGame(vector<string>& ref_list)
{
	string gameTitle;

	vector<string>::iterator iter;

	cout << "Enter a game name: " << endl;
	cin.ignore(1024, '\n');
	getline(cin, gameTitle);

	iter = find(ref_list.begin(), ref_list.end(), gameTitle);

	if (iter != ref_list.end())
	{
		ref_list.erase(iter); 
		cout << endl << "\t " << gameTitle << " removed." << endl;
	}
	else{
		cout << endl << "\t TITLE DOES NOT EXIST." << endl;
	}
	cout << endl;
}

