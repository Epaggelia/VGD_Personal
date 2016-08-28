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
#include "Binary.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	int codeLength;
	int guessLimit;
	int userInput;

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
		bool mode = true;
		string code = "";
		string guess = "";
		int guesses = 0;

		cout << "Select a mode or Exit:" << endl <<
			"\t[1] Guess code" << "\t(Guess the code created by the computer)" << endl <<
			"\t[2] Make code" << "\t(Create a code for the computer to guess)" << endl <<
			"\t[3] Exit" << endl <<
			"\t> ";
		do
		{
			userInput = getValidInt();

			if (userInput == 1)
			{
				mode = true;
				break;
			}
			else if (userInput == 2)
			{
				mode = false;
				break;
			}
			else if (userInput == 3)
			{
				end = true;
				break;
			}
			else
			{
				cout << "\tInvalid input." << endl << "\t> ";
			}
		} while (true);

		cout << endl;

		if (end)
			break;

		cout << "Select a code difficultly:" << endl <<
			"\t[1] Easy" << "\t4 digits - 5 guesses" << endl <<
			"\t[2] Medium" << "\t5 digits - 7 guesses" << endl <<
			"\t[3] Hard" << "\t6 digits - 8 guesses" << endl <<
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
			else
			{
				cout << "\tInvalid input." << endl << "\t> ";
			}
		} while (true);
		
		system("cls");

		//create code
		if (mode)		//computer generated
		{
			code = genCode(codeLength);
			cout << "New " << code.length() << " digit code created." << endl << "> ";
		}
		else			//player generated
		{
			cout << "Create a " << codeLength << " digit code using 1 and 0." << endl << "> ";
			do
			{
				cin >> code;
			} while (!checkValid(code, codeLength));
			system("cls");
		}

		int check = 0;
		int firstCheck = 0;
		string lastGuess;

		do
		{
			//get guess
			if (mode)	//player guess
			{
				do
				{
					cin >> guess;
				} while (!checkValid(guess, code.length()));
			}
			else		//computer guess
			{
				cout << "Computers guess" << endl << "> ";

				lastGuess = guess;
				guess = "";

				if (guesses == 1)
					firstCheck = check;
				
				guess = computerGuess(guesses, check, firstCheck, code.length(), lastGuess);

				cout << guess << endl;
			}

			guesses += 1;

			check = 0;

			//check for matches
			check = checkMatch(code, guess);

			//checking state
			if (check == code.length())
			{
				cout << (mode ? "You" : "The computer") << " got the code." << endl << (mode ? "You" : "The computer") << " win" << (mode ? "." : "s.") << endl << endl;
				break;
			}
			else if (guesses < guessLimit)
			{
				cout << endl << (mode ? "You" : "The computer")<<" got " << check << " out of " << code.length() << " digits correct." << endl;
				cout << (mode ? "You have " : "The computer has ") << guessLimit - guesses << " guesses remaining." << endl << endl;
				if (mode)
					cout << "Take your next guess.." << endl << "> ";
			}
			else
			{
				cout << (mode ? "You have" : "The computer has") << " failed to break the code." << endl << "The code was " << code << "." << endl << endl;
				break;
			}
		} while (true);
		
		system("PAUSE");
		system("cls");

	} while (true);

	return 0;
}
