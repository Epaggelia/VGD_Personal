/*
RPG Character Maker
Write a program that simulates the character creation process found in most RPG games.
The character must be defined by the following traits: name, race, class, strength,
dexterity, constitution, wisdom, intelligence, and charisma.

•	The character data must be stored inside a c++ class called Character.
The functionality of the class is up to you (think about what data members
you need, and what access you require).
•	The user can enter name, race, and class manually (BONUS: Only allow name
to be entered manually. Race and class are selected from a list of predefined
options*).
•	The 6 traits cannot be lower than 8 or greater than 18. Use 10 as an average,
and randomize between -2 and 8 to ADD to the base value.
•	Write a Character class function called Display that will show the character’s
traits in a readable format. Use this function to show the character after the
creation process.
•	Ask the user if they are happy with the results. If not, generate the character
again.
•	*BONUS: Add bonuses or penalties to the traits based on race/class selection.
The details of which are up to you (e.g. picking an Elf class assigns a bonus
of +2 dex, but -2 str). The bonuses CAN modify the stats beyond the range of 8 – 18.
*/
#include <iostream>
#include <ctime>
#include "character.h"

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;

bool confirm();

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	do
	{
		Character char_;
		char_.display();
	} while (confirm());


	system("pause");
	return 0;
}


bool confirm()
{
	string userInput;
	cout << "Do you accept this character: \t(Yes/No)" << endl;
	do
	{
		cout << "> ";
		cin >> userInput;
		if (userInput == "Yes" || userInput == "yes" || userInput == "Y" || userInput == "y")
		{
			cout << "Enjoy the game." << endl;
			return false;
		}
		else if (userInput == "No" || userInput == "no" || userInput == "N" || userInput == "n")
		{
			system("cls");
			return true;
		}
		else
		{
			cout << endl << "Invalid Input." << endl;
		}
	} while (true);
}