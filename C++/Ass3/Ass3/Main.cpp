#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using std::find;

enum CARD_SUIT { HEART = 3, DIAMOND, CLUB, SPADE };

int randHand(vector<int>& handGive, vector<int>& handCheck);
void sortHand(vector<int>& hand);
void printHand(vector<int>& hand);
bool menu();


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int HAND_SIZE = 5;
	int deck[52];
	vector<int> hand1;
	vector<int> hand2;

	//fill deck and print
	for (int i = 0; i < 52; i++)
	{
		deck[i] = i;
	}
	while (!menu())
	{
		//random hand
		hand1.erase(hand1.begin(), hand1.end());
		hand2.erase(hand2.begin(), hand2.end());

		for (int i = 0; i < 5; i++)
		{
			hand1.push_back(randHand(hand1, hand2));
			hand2.push_back(randHand(hand2, hand1));
		}

		//sort hand
		sortHand(hand1);
		sortHand(hand2);

		cout << endl;

		//print card
		printHand(hand1);
		printHand(hand2);

		cout << endl;

		system("pause");
		system("cls");
	}


	////////////////////////
	//check hand -- poker // 
	////////////////////////
	/*
	int high = 0;

	high = hand1[4] % 13; // highest card in hand

	int straight = 0;
	int flush = 0;
	int straightFlush = 0;
	int royalFlush = 0;

	int fullHouse = 0;
	int fourOfAKind = 0;
	int threeOfAKind = 0;
	int pair = 0;
	int nothing = 0;
	int twoPair = 0;

	//straight
	if (hand1[0] % 13 == hand1[1] % 13 - 1 &&
	hand1[1] % 13 == hand1[2] % 13 - 1 &&
	hand1[2] % 13 == hand1[3] % 13 - 1 &&
	hand1[3] % 13 == hand1[4] % 13 - 1)
	{
	straight += 1;
	high = hand1[4] % 13;
	}
	//flush
	if (hand1[0] / 13 == hand1[1] / 13 &&
	hand1[1] / 13 == hand1[2] / 13 &&
	hand1[2] / 13 == hand1[3] / 13 &&
	hand1[3] / 13 == hand1[4] / 13)
	{
	flush += 1;
	high = hand1[4] % 13;
	}

	if (straight == 1 || flush == 1)
	{
	//straight flush
	if (straight == 1 && flush == 1)
	{
	straightFlush += 1;
	straight = 0;
	flush = 0;
	high = hand1[4] % 13;
	}
	//royal flush
	if (flush == 1)
	{
	if (hand1[0] % 13 == 0 && hand1 &&
	hand1[1] % 13 == 9 && hand1 &&
	hand1[2] % 13 == 10 && hand1 &&
	hand1[3] % 13 == 11 && hand1 &&
	hand1[4] % 13 == 12 && hand1)
	{
	royalFlush += 1;
	flush = 0;
	high = hand1[4] % 13;
	}
	}
	}
	else
	{
	//four of a kind
	for (size_t i = 0; i < 2; i++)
	{
	if (hand1[i] % 13 == hand1[i + 1] % 13 && hand1[i + 1] % 13 == hand1[i + 2] % 13 && hand1[i + 2] % 13 == hand1[i + 3] % 13)
	{
	fourOfAKind += 1;
	high = hand1[i + 3] % 13;
	}
	}

	if (fourOfAKind == 0)
	{
	//full house
	if (hand1[0] % 13 == hand1[1] % 13)
	{
	if (hand1[2] % 13 == hand1[3] % 13 &&
	hand1[3] % 13 == hand1[4] % 13)
	{
	fullHouse += 1;
	high = hand1[4] % 13;
	}
	}
	if (hand1[0] % 13 == hand1[1] % 13 && hand1[1] % 13 == hand1[2] % 13)
	{
	if (hand1[3] % 13 == hand1[4] % 13)
	{
	fullHouse += 1;
	high = hand1[4] % 13;
	}
	}

	if (fullHouse == 0)
	{
	//three of a kind
	for (size_t i = 0; i < 3; i++)
	{
	if (hand1[i] % 13 == hand1[i + 1] % 13 && hand1[i + 1] % 13 == hand1[i + 2] % 13)
	{
	threeOfAKind += 1;
	high = hand1[i + 2] % 13;
	}
	}
	if (threeOfAKind == 0)
	{
	//pair
	for (size_t i = 0; i < 5; i++)
	{
	if (hand1[i] % 13 == hand1[i + 1] % 13)
	{
	pair += 1;
	high = hand1[i + 1] % 13;
	}
	}
	if (pair == 0) // hand1 of nothing
	{
	nothing += 1;
	}
	else if (pair == 2)//two pair
	{
	pair = 0;
	twoPair = 1;
	}
	}
	}
	}
	}
	*/
	//////////////////////
	//////////////////////

	cout << endl;

	return 0;
}

bool menu()
{
	do
	{
		int userInput;

		cout << "[1] Better Hand \t(Ass3a)" << endl;
		cout << "[2] War \t\t(Ass3b)" << endl;
		cout << "[3] Black Jack \t\t(Ass3c)" << endl;
		cout << "[0] Quit" << endl;
		cout << "> ";
		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			system("cls");
			continue;
		}
		if (userInput <0 || userInput>3)
		{
			system("cls");
			continue;
		}

		if (userInput == 1)
		{
			return false;
		}
		else if (userInput == 2)
		{
			return false;
		}
		else if (userInput == 3)
		{
			return false;
		}
		else if (userInput == 0)
		{
			return true;
		}
		cout << endl;
		return false;
	} while (true);
}

int randHand(vector<int>& handGive, vector<int>& handCheck)
{
	int randomCard;
	bool check = false;
		do
		{
			randomCard = (rand() % 52);
			for (size_t i = 0; i < handGive.size(); i++)
			{
				cout << "Checking";
				if (handGive.at(i) == randomCard)
				{
					check = true;
				}
				else if (handCheck.at(i) == randomCard)
				{
					check = true;
				}
			}
		} while (check);
	return randomCard;
}

void sortHand(vector<int>& hand)
{
	int temp;
	for (int i = 0; i < 5; i++){
		for (int j = i + 1; j<5; j++){
			if ((hand.at(i)) % 13>(hand.at(j)) % 13){
				temp = hand.at(i);
				hand.at(i) = hand.at(j);
				hand.at(j) = temp;
			}
		}
	}
}

void printHand(vector<int>& hand)
{
	//print card value
	for (int i = 0; i < 5; i++)
	{
		if (hand.at(i) % 13 == 0)
		{
			cout << "A" << " ";
		}
		else if (hand.at(i) % 13 == 10)
		{
			cout << "J" << " ";
		}
		else if (hand.at(i) % 13 == 11)
		{
			cout << "Q" << " ";
		}
		else if (hand.at(i) % 13 == 12)
		{
			cout << "K" << " ";
		}
		else
		{
			cout << (hand.at(i) % 13) + 1 << " ";
		}
		if ((hand.at(i) % 13) + 1 != 10)
			cout << " ";
	}

	cout << endl;

	//print card suit
	for (int i = 0; i < 5; i++)
	{
		char asciiChar;

		if (hand.at(i) / 13 == 0)
		{
			asciiChar = 3;
		}
		else if (hand.at(i) / 13 == 1)
		{
			asciiChar = 4;
		}
		else if (hand.at(i) / 13 == 2)
		{
			asciiChar = 5;
		}
		else if (hand.at(i) / 13 == 3)
		{
			asciiChar = 6;
		}
		cout << asciiChar << "  ";
	}
	cout << endl << endl;
}