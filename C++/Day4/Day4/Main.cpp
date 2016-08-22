#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::rand;
using std::srand;
using std::time;

int getRandom(int min, int max);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	enum FIELDS{ WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{ "wall", "Banging your head against something?" },
		{ "glasses", "These might help you see the answer." },
		{ "labored", "Going slowly, is it?" },
		{ "persistant", "Don't you ever give up?" },
		{ "jumble", "It's what this game is all about!" },
		{ "element", "Another name for html tags." },
		{ "water", "Man, I'm thirsty." },
		{ "pencil", "You write with this." },
		{ "marker", "It's black." },
		{ "phone", "Don't call me." },
	};

	int choice = getRandom(0, NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];

	string jumbled = theWord;
	int length = jumbled.size();
	for (int i = 0; i < length; i++)
	{
		int index1 = getRandom(0, length);
		int index2 = getRandom(0, length);
		char temp = jumbled[index1];
		jumbled[index1] = jumbled[index2];
		jumbled[index2] = temp;
	}



	string guess;

	cout << "\tWelcome to word Jumble!" << endl;
	cout << "Wnscrable the letters to make a word." << endl;
	cout << "Enter \"hint\" for a hint." << endl;
	cout << "Enter \"quit\" to give up." << endl;
	cout << "Here is your jumble: " << jumbled << endl << endl;

	cout << jumbled << endl;

	const int tryLimit = 5;
	int tryCount = 0;

	do
	{
		cout << "Enter your guess: \a";
		cin >> guess;
		tryCount += 1;

		if (guess == "quit" || guess == "quit")
		{
			continue;
		}
		else if (guess == "hint")
		{
			cout << theHint << endl << endl;
		}
		else if (guess != theWord)
		{
			cout << "Your wrong, try again." << endl << endl;
		}
		else
		{
			cout << "That's right! You got it!" << endl << endl;
		}
	} while (guess != theWord && guess != "quit" && tryCount < tryLimit);

	if (guess != theWord)
	{
		cout << "The word was " << theWord << "." << endl;
	}

	system("PAUSE");
	return 0;
}


int getRandom(int min, int max)
{
	return int(rand() % (max-min) + min -1);
}