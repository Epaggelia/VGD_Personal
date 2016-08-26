/*
Binary Code Breaker
In the game Binary Code Breaker, the player must guess a four - digit code made up of 1’s and 0’s.The player submits a guess by entering each of the four digits either through separate prompts or as a single four - digit entry(harder).After the player enters the last digit of a guess, the computer lets him or her know how many digits matched the secret code.
•	If the player guesses the complete four - digit code in five or fewer guesses, he or she wins; otherwise, it’s game over.
•	The previous guess should be displayed for reference.
•	Input should be restricted to the values 0 and 1.
•	Present the correct number of digits as a total ONLY.Do not indicate which digits are correct.This would make the game far too easy.
•	Make the program ask if the player would like to play again, and loop until the answer is no.
•	BONUS : Create a menu that allows the user to select the difficulty of the code(i.e.easy, medium, hard) and adjust code size and guesses allowed accordingly.
•	BONUS : Re - write the program so the user has the option to create a code and have the computer try to guess.
I will be checking COMMENTS, WHITESPACE USE, PROPER NAMING CONVENTIONS, and ERROR CHECKING.

Example :
Code Breaker : Binary Edition.
1. Start game.
2. Quit.
*/

#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;
using std::srand;
using std::time;
using std::to_string;

int getRandom(int min, int max);
bool checkValid(string text);


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	do
	{
		string code = "";
		string guess = "";

		for (int i = 0; i < 4; i++)
		{
			code += to_string(rand() % 100 > 50 ? 1 : 0);
		}

		cout << code << endl;

		do
		{
			cin >> guess;
		} while (checkValid(guess));

		int check = 0;

		for (int i = 0; i < code.length(); i++)
		{
			if (code.at(i) == guess.at(i))
			{
				check += 1;
			}
		}

		cout << check << endl;
	} while (true);

	system("PAUSE");
	return 0;
}

///////////////////////////////////////////////

int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}

bool checkValid(string text)
{
	bool check = false;
	if (text.length() != 4)
	{
		cout << "4 character input needed." << endl;
		check = true;
	}
	else
	{
		for (int i = 0; i < text.length(); i++)
		{
			cout << text.at(i) << endl;
			switch (text.at(i))
			{
			case 0:
				break;
			case 1:
				break;
			default:
				cout << "Only input binary numbers." << endl;
				check = true;
				break;
			}
		}
	}

	return check;
}

