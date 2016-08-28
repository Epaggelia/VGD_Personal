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

int getValidInt();
bool checkValid(string text, int num);
string genCode(int codeLength);
string codeFlip(string text);
string computerGuess(int guesses, int check, int firstCheck, int codeLength, string lastGuess);
string randomGuess(int codeLength, int check);
int checkMatch(string code, string guess);

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
		for (size_t i = 0; i < text.length(); i++)
		{
			if (text.at(i) == '0' || text.at(i) == '1')
			{
				//
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

string genCode(int codeLength)
{
	string code;
	for (int i = 0; i < codeLength; i++)
	{
		code += to_string(rand() % 100 > 50 ? 1 : 0);
	}

	return code;
}

string codeFlip(string text)
{
	string newText = "";
	for (size_t i = 0; i < text.length(); i++)
	{
		if (text.at(i) == '0')
		{
			newText += '1';
		}
		else if (text.at(i) == '1')
		{
			newText += '0';
		}
	}
	return newText;
}

string computerGuess(int guesses, int check, int firstCheck, int codeLength, string lastGuess)
{
	string guess = "";
	if (guesses == 0)
	{
		for (int i = 0; i < codeLength; i++)
		{
			guess += '1';
		}
	}
	else if (check == 0)
	{
		guess = codeFlip(lastGuess);
	}
	else if (firstCheck == codeLength - 1 || firstCheck == 1)
	{
		for (int i = 0; i < codeLength; i++)
		{
			if (i == guesses - 1)
			{
				guess += '0';
			}
			else
			{
				guess += '1';
			}
		}

		if (firstCheck == 1)
			guess = codeFlip(guess);
	}
	else if (firstCheck == codeLength / 2 && codeLength == 4)
	{
		if (guesses == 1)
		{
			guess = "0011";
		}
		else if (guesses == 2)
		{
			guess = "1001";
		}
		else if (guesses == 3)
		{
			guess = "0101";
		}
	}
	else
	{
		guess = randomGuess(codeLength, firstCheck);
	}

	return guess;
}

string randomGuess(int codeLength, int check)
{
	char a[6];
	string newCode = "";

	for (int i = 0; i < codeLength - check; i++)
	{
		a[i] = '0';
	}

	for (int i = codeLength - check; i < codeLength; i++)
	{
		a[i] = '1';
	}

	for (int i = 0; i < codeLength; i++)
	{
		char temp = a[i];
		int roll = rand() % codeLength;
		a[i] = a[roll];
		a[roll] = temp;
	}

	for (int i = 0; i < codeLength; i++)
	{
		newCode += a[i];
	}

	return newCode;
}

int checkMatch(string code, string guess)
{
	int check = 0;
	for (size_t i = 0; i < code.length(); i++)
	{
		if (code.at(i) == guess.at(i))
		{
			check += 1;
		}
	}
	return check;
}


