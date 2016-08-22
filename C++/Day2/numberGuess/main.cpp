#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;
using std::time;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int secretNumber = rand() % 100 + 1;
	int guess = 0;
	int tries = 0;
	const int GUESS_LIMIT = 5;

	cout << "\tGuess My Number!" << endl << endl;

	cout << "I'm thinking of a number between 1 and 100." << endl; 
	cout << "Try to guess it!" << endl;

	do
	{
		cout << "Enter a guess [1-100]: ";
		cin >> guess;
		 
		tries++;

		if (guess > secretNumber)
		{
			cout << "Too high, sorry!" << endl;
		}
		else if (guess < secretNumber)
		{
			cout << "Too low, sorry!" << endl;
		}
		else
		{
			cout << "That's correct! You got it!" << endl;
		}

		if (tries >= GUESS_LIMIT && guess != secretNumber)
		{
			cout << "You have run out of guesses." << endl;
			cout << "The number was " << secretNumber << endl;
			break;
		}
	} while (guess != secretNumber);

	system("PAUSE");
	return 0;
}