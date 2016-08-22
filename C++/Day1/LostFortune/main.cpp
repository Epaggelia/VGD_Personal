#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	const int GOLD_PIECES = 900;

	string name = "";
	int adventurers = 0;
	int killed = 0;

	cout << "\tWelcome to Lost Fortune." << endl << endl;
	cout << "Please follow the instructiions, and enter in the following information.";
	cout << endl << endl;

	cout << "Enter your last name : ";
	cin >> name;

	cout << "Enter a positive number: ";
	cin >> adventurers;

	cout << "enter a postive number, less than the first: ";
	cin >> killed;

	//calculate new values
	int survivors = adventurers - killed;
	int extraGoldPieces = GOLD_PIECES % survivors;

	//tell the story
	cout << endl;
	cout << "The brave " << name << " led a group of " << adventurers;
	cout << " adventurers on a quest." << endl;
	cout << "They fought a band of ogres and lost " << killed << "... only ";
	cout << survivors << " survived." << endl;

	cout << "The party was about to give up when they stumbled upon a" << endl;
	cout << "buried fortune of " << GOLD_PIECES << " gold peices. ";
	cout << "They split the loot and" << endl;
	cout << name << " kept the extra " << extraGoldPieces << " gold piece(s)";
	cout << " to keep things fair." << endl;
	
	return 0;


}