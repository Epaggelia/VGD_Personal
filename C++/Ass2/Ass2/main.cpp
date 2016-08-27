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
bool checkValid(string text, int num);
int getValidInt();


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	cout << "\tBinary Code Breaker" << endl << endl <<
		"In the game Binary Code Breaker, the player must guess a code made up of" <<endl<<
		"1's and 0's." << endl << endl <<
		"The player submits a guess by entering the four digits as a single entry." << endl << endl <<
		"After the player enters the guess, the computer lets you know how many" << endl <<
		"digits matched the secret code." << endl << endl; 

	system("PAUSE");
	system("cls");

	do
	{
		bool end = false;
		string code = "";
		string guess = "";
		int guesses = 0;
		int codeLength;
		int guessLimit;

		int userInput;
		cout << "Select a code difficultly or Exit:" << endl <<
			"\t[1] Easy" << endl <<
			"\t[2] Medium" << endl <<
			"\t[3] Hard" << endl << 
			"\t[4] Exit" << endl <<
			"\t> ";

		do
		{
			userInput = getValidInt();

			if (userInput == 1)
			{
				codeLength = 4;
				guessLimit = 5;
				break;
			}
			else if (userInput == 2)
			{
				codeLength = 5;
				guessLimit = 7;
				break;
			}
			else if (userInput == 3)
			{
				codeLength = 6;
				guessLimit = 8;
				break;
			}
			else if (userInput == 4)
			{
				end = true;
				break;
			}
			else
			{
				cout << "\tInvalid input." << endl << "\t> ";
			}
		} while (true);
		
		system("cls");

		if (end)
			break;
		
		//rand code
		for (int i = 0; i < codeLength; i++)
		{
			code += to_string(rand() % 100 > 50 ? 1 : 0);
		}

		cout << "New " << code.length() << " digit code created."<< endl << "> ";

		do
		{
			//get guess
			do
			{
				cin >> guess;
			} while (!checkValid(guess, code.length()));

			guesses += 1;

			int check = 0;

			//check for matches
			for (int i = 0; i < code.length(); i++)
			{
				if (code.at(i) == guess.at(i))
				{
					check += 1;
				}
			}

			//checking state
			if (check == code.length())
			{
				cout << "You got the code." << endl << "You win." << endl << endl;
				break;
			}
			else if (guesses < guessLimit)
			{
				cout <<endl << "You got " << check << " out of " << code.length() << " digits correct." << endl;
				cout << "You have " << guessLimit - guesses << " guesses remaining." << endl << endl;
				cout << "Take your next guess.." << endl << "> ";
			}
			else
			{
				cout << "You have failed to break the code." << endl << "The code was " << code << "." << endl << endl;
				break;
			}
		} while (true);
		
		system("PAUSE");
		system("cls");

	} while (true);

	return 0;
}

///////////////////////////////////////////////

int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}

int getValidInt()
{
	int userInput;

	if (!(cin >> userInput))
	{
		cin.clear();
		cin.ignore(1024, '\n');

		return -1;
	}
	return userInput;
}

bool checkValid(string text, int num)
{
	bool check = true;
	if (text.length() != num)
	{
		cout << num << " character input needed." << endl;
		check = false;
	}
	else
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text.at(i) == '0' || text.at(i) == '1')
			{
				/**/
			}
			else
			{
				check = false;
			}
		}
		if (!check)
			cout << "Only input binary numbers." << endl;
	}
	
	return check;
}

