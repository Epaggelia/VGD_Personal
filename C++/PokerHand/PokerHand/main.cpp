#include <iostream>
#include <fstream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using namespace std;

int getRandom(int min, int max);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	int deck[52];

	//fill deck and print
	for (size_t i = 0; i < 52; i++)
	{
		deck[i] = i;
		if (deck[i] % 13 == 0)
			cout << endl;
		if (i < 10)
			cout << "0";
		cout << deck[i] << " ";
	}

	cout << endl;
	system("PAUSE");
	cout << endl;

	int loops = 0;

	int storeNothing = 0;
	int storePair = 0;
	int storeTwoPair = 0;
	int storeThreeOfAKind = 0;
	int storeStraight = 0;
	int storeFlush = 0;
	int storeFullHouse = 0;
	int storeFourOfAKind = 0;
	int storeStraightFlush = 0;
	int storeRoyalFlush = 0;

	do
	{
		int hand[5] = {};
		
		//random hand
		for (size_t i = 0; i < 5; i++)
		{
			int randomCard;
			do
			{
				randomCard = (rand() % 52);
			} while (hand + 5 != find(hand, hand + 5, randomCard));
			hand[i] = randomCard;
		}

		//print hand values
		/*
		for (size_t i = 0; i < 5; i++)
		{
			cout << hand[i] << " ";
		}
		*/

		//sort hand
		int temp;
		for (int i = 0; i<5; i++){
			for (int j = i + 1; j<5; j++){
				if ((hand[i]) % 13>(hand[j])%13){
					temp = hand[i];
					hand[i] = hand[j];
					hand[j] = temp;
				}
			}
		}

		//cout << endl;

		//print hand values
		/*
		for (size_t i = 0; i < 5; i++)
		{
			cout << hand[i] << " ";
		}
		*/

		//cout << endl;

		//print card value
		for (size_t i = 0; i < 5; i++)
		{
			
			if (hand[i] % 13 == 0)
			{
				cout << "A" << " ";
			}
			else if (hand[i] % 13 == 10)
			{
				cout << "J" << " ";
			}
			else if (hand[i] % 13 == 11)
			{
				cout << "Q" << " ";
			}
			else if (hand[i] % 13 == 12)
			{
				cout << "K" << " ";
			}
			else
			{
				cout << (hand[i] % 13)+1 << " ";
			}
		}
		
		cout << endl;

		//print card suit
		for (size_t i = 0; i < 5; i++)
		{
			char asciiChar;

			if (hand[i] / 13 == 0)
			{
				asciiChar = 3;
			}
			else if (hand[i] / 13 == 1)
			{
				asciiChar = 4;
			}
			else if (hand[i] / 13 == 2)
			{
				asciiChar = 5;
			}
			else if (hand[i] / 13 == 3)
			{
				asciiChar = 6;
			}
			cout << asciiChar << " ";
		}
		
		cout << endl;
		
		//check hand
		///////////////////////////////////////////////////////////////////////
		int high = 0;

		high = hand[4] % 13; // highest card in hand 

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
		if (hand[0] % 13 == hand[1] % 13 - 1 &&
			hand[1] % 13 == hand[2] % 13 - 1 &&
			hand[2] % 13 == hand[3] % 13 - 1 &&
			hand[3] % 13 == hand[4] % 13 - 1)
		{
			straight += 1;
			high = hand[4] % 13;
		} 
		//flush
		if (hand[0] / 13 == hand[1] / 13 &&
			hand[1] / 13 == hand[2] / 13 &&
			hand[2] / 13 == hand[3] / 13 &&
			hand[3] / 13 == hand[4] / 13)
		{
			flush += 1;
			high = hand[4] % 13;
		}

		if (straight == 1 || flush == 1)
		{
			//straight flush
			if (straight == 1 && flush == 1)
			{
				straightFlush += 1;
				straight = 0;
				flush = 0;
				high = hand[4] % 13;
			}
			//royal flush
			if (flush == 1)
			{
				if (hand[0] % 13 == 0 && hand &&
					hand[1] % 13 == 9 && hand &&
					hand[2] % 13 == 10 && hand &&
					hand[3] % 13 == 11 && hand &&
					hand[4] % 13 == 12 && hand)
				{
					royalFlush += 1;
					flush = 0;
					high = hand[4] % 13;
				}
			}
		}
		else
		{
			//four of a kind
			for (size_t i = 0; i < 2; i++)
			{
				if (hand[i] % 13 == hand[i + 1] % 13 && hand[i + 1] % 13 == hand[i + 2] % 13 && hand[i + 2] % 13 == hand[i + 3] % 13)
				{
					fourOfAKind += 1;
					high = hand[i + 3] % 13;
				}
			}

			if (fourOfAKind == 0)
			{
				//full house
				if (hand[0] % 13 == hand[1] % 13)
				{
					if (hand[2] % 13 == hand[3] % 13 &&
						hand[3] % 13 == hand[4] % 13)
					{
						fullHouse += 1;
						high = hand[4] % 13;
					}
				}
				if (hand[0] % 13 == hand[1] % 13 && hand[1] % 13 == hand[2] % 13)
				{
					if (hand[3] % 13 == hand[4] % 13)
					{
						fullHouse += 1;
						high = hand[4] % 13;
					}
				}
				
				if (fullHouse == 0)
				{
					//three of a kind
					for (size_t i = 0; i < 3; i++)
					{
						if (hand[i] % 13 == hand[i + 1] % 13 && hand[i + 1] % 13 == hand[i + 2] % 13)
						{
							threeOfAKind += 1;
							high = hand[i + 2] % 13;
						}
					}
					if (threeOfAKind == 0)
					{
						//pair
						for (size_t i = 0; i < 5; i++)
						{
							if (hand[i] % 13 == hand[i + 1] % 13)
							{
								pair += 1;
								high = hand[i + 1] % 13;
							}
						}
						if (pair == 0) // hand of nothing
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
		//////////////////////////////////////////////////////////////////////////

		//store hands
		storeNothing += nothing;
		storePair += pair;
		storeTwoPair += twoPair;
		storeThreeOfAKind += threeOfAKind;
		storeStraight += straight;
		storeFlush += flush;
		storeFullHouse += fullHouse;
		storeFourOfAKind += fourOfAKind;
		storeStraightFlush += straightFlush;
		storeRoyalFlush += royalFlush;		

		cout << endl;
		loops += 1;
		
	} while (loops < 10000);

	system("cls");
	cout << "Processing complete." << endl << "Continue to save to Values.txt" << endl;
	system("PAUSE");
	system("cls");

	ofstream myfile;
	myfile.open("test.txt");
	myfile << "Sample Size = " << loops << "\n\n" <<
		"Nothing : \n\t\t\t" << storeNothing << "\n" << 
		"Pair : \n\t\t\t" << storePair << "\n" <<
		"Two Pair : \n\t\t\t" << storeTwoPair << "\n" <<
		"Three of a kind : \n\t\t\t" << storeThreeOfAKind << "\n" <<
		"Straight : \n\t\t\t" << storeStraight << "\n" <<
		"Flush : \n\t\t\t" << storeFlush << "\n" <<
		"Full house : \n\t\t\t" << storeFullHouse << "\n" <<
		"Four of a kind : \n\t\t\t" << storeFourOfAKind << "\n" <<
		"Straight flush : \n\t\t\t" << storeStraightFlush << "\n" <<
		"Royal flush : \n\t\t\t" << storeRoyalFlush << "\n";
	myfile.close();

	cout << "Program complete." << endl;
	system("PAUSE");

	return 0;
}

int getRandom(int min, int max)
{
	return int(rand() % (max - min + 1) + min);
}