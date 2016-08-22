#include <iostream>

using namespace std;

const int ALIEN_POINTS = 50;

int main()
{
	// RAII	- Resource acquisition is initialization
	int score = 0;
	double distance = 1200.76;
	char playAgain = 'y';
	bool shieldsUp = true;

	//interger is a 4-byte whole number
	//short is a 2-byte whole number

	short lives, aliensKilled;
	lives = 3;
	aliensKilled = 0;

	cout << "Score: " << score << endl;

	cin >> score;
	cout << score << endl;

	/*cout << "My first c++ program." << endl;

	cout << "7 + 3 = " << 7 + 3 << endl;
	cout << "7 / 3 = " << 7 / 3 << endl;
	cout << "7.0 / 3.0 = " << 7.0 / 3.0 << endl;
	cout << "7 % 3 = " << 7 % 3 << endl;
	cout << "7 + 3 * 5 = " << 7 + 3 * 5 << endl;
	cout << "(7 + 3) * 5 = " << (7 + 3) * 5 << endl;*/

	system("PAUSE");
	return 0;
}