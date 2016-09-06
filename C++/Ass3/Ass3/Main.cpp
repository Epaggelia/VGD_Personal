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
const char FACE_DOWN = 176;
const char NO_SUIT = 158;

int drawCard(vector<int>& handGive, vector<int>& deck);
void sortHand(vector<int>& hand);
void printHand(vector<int>& hand);
void printValue(int i);
void printSuit(int i);
int handTotal(vector<int>& hand);

bool refillDeck(vector<int>& deck, vector<int>& pile);

bool menu(vector<int>& hand1, vector<int>& hand2, vector<int>& deck);
void betterHand(vector<int>& hand1, vector<int>& hand2, vector<int>& deck);
void war(vector<int>& hand1, vector<int>& hand2, vector<int>& deck);
bool warHand(vector<int>& hand, vector<int>& deck,vector<int>& pile);
void blackJack(vector<int>& hand1, vector<int>& hand2, vector<int>& deck);
void blackJackPrintHands(vector<int>& hand1, vector<int>& hand2);
int blackJackCheck(vector<int>& hand);
bool blackJackCompare(vector<int>& hand1, vector<int>& hand2);



int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int HAND_SIZE = 5;
	vector<int> deck;
	vector<int> hand1;
	vector<int> hand2;
	
	do
	{
		//fill deck
		for (int i = 0; i < 52; i++)
		{
			deck.push_back(i);
		}
		for (size_t i = 0; i < deck.size(); i++)
		{
			int temp = deck.at(i);
			int roll = rand() % deck.size();
			deck.at(i) = deck.at(roll);
			deck.at(roll) = temp;
		}

	} while (!menu(hand1, hand2, deck));

	cout << endl;

	return 0;
}

bool menu(vector<int>& hand1, vector<int>& hand2,vector<int>& deck)
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
			betterHand(hand1,hand2,deck);
			return false;
		}
		else if (userInput == 2)
		{
			war(hand1, hand2, deck);
			return false;
		}
		else if (userInput == 3)
		{
			blackJack(hand1, hand2, deck);
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

//Better Hand
/*
In this simple card game, two 5-card hands are dealt and their values are summed together.
The hand with the higher value is deemed the winner. Treat aces as having a value of 1,
and face cards as their standard value (i.e. jack = 11, queen = 12, king = 13).
This game doesn’t require user input beyond showing the results of the hands. Allows 
players to review the results of the round before continuing.
The game should show the cards for both players’ hands, as well as their total.
Cards should never be duplicated, either in the same hand or between hands.
The game should announce the winner of each round.
Make the program ask if the players would like to play again, and loop until the answer is no.
I will be checking COMMENTS, WHITESPACE USE, PROPER NAMING CONVENTIONS, and ERROR CHECKING.
*/

void betterHand(vector<int>& hand1,vector<int>& hand2, vector<int>& deck)
{
	system("cls");

	hand1.erase(hand1.begin(), hand1.end());
	hand2.erase(hand2.begin(), hand2.end());

	//random hand
	for (int i = 0; i < 5; i++)
	{
		hand1.push_back(drawCard(hand1, deck));
		hand2.push_back(drawCard(hand2, deck));
	}

	//sort hand
	sortHand(hand1);
	sortHand(hand2);
	
	//print card
	cout << "Player 1: " << endl;
	printHand(hand1);
	cout << "Player 2: " << endl;
	printHand(hand2);

	//hand totals
	int hand1Total = handTotal(hand1);
	int hand2Total = handTotal(hand2);

	//game output
	cout << endl << "Player 1 Total: ";
	cout << hand1Total;
	
	cout << endl << "Player 2 Total: ";
	cout << hand2Total;

	cout << endl << endl;

	if (hand1Total == hand2Total)
	{
		cout << "It is a tie, there is no winner." << endl;
	}
	else
	{
		cout << "The winner is " << (hand1Total > hand2Total ? "Player 1" : "Player 2") << endl;
	}

	cout << endl;

	system("pause");
	system("cls");
}

//War
/*
In the game of War 2 players split the deck evenly, giving each a face-down stack. 
In unison, each player reveals the top card of their deck. The player who reveals 
the higher-value card takes both cards and adds them to a “victory” pile. Once a 
player’s stack has no more cards to reveal, that player shuffles their “victory”
pile back into their hand and play continues. If a player has no cards remaining 
in their stack or “victory” pile, that player loses. If players reveal cards with 
equivalent values, there is a “war”. Both players place one card face down, and then 
reveal an additional card. Whoever revealed the higher-value card adds all 6 cards to 
their “victory” pile. If the new cards are equivalent values, another war takes place. 
This repeats until one player wins the war. Ace is the highest value card, and suits are irrelevant.

This game doesn’t require user input beyond showing the results of the next card reveal. 
Allows players to review the results of the reveal before continuing with the game.

Totals for both players stack and “victory” piles should be updated and visible between rounds.

The winner of each round should be announced, to keep the players informed of the game’s progress.

The program should never try to draw a card from an empty stack. This is more likely to 
occur during the war phase.

Make the program ask if the player would like to play again, and loop until the answer is no.

BONUS: Add a quit feature, to allow players to exit during gameplay.

I will be checking COMMENTS, WHITESPACE USE, PROPER NAMING CONVENTIONS, and ERROR CHECKING.
*/

void war(vector<int>& hand1, vector<int>& hand2, vector<int>& deck)
{
	system("cls");
	bool endGame = false;
	
	vector<int> player1Deck;
	vector<int> player2Deck;

	vector<int> victoryPile1;
	vector<int> victoryPile2;

	//split deck
	for (size_t i = 0; i < 52/2; i++)
	{
		player1Deck.push_back(deck.front());
		deck.erase(deck.begin());
		player2Deck.push_back(deck.front());
		deck.erase(deck.begin());
	}

	do{
		//clean hand
		hand1.erase(hand1.begin(), hand1.end());
		hand2.erase(hand2.begin(), hand2.end());

		//draw card - player1
		hand1.push_back(player1Deck.front());
		player1Deck.erase(player1Deck.begin());
		refillDeck(player1Deck, victoryPile1);

		//draw card - player2
		hand2.push_back(player2Deck.front());
		player2Deck.erase(player2Deck.begin());
		refillDeck(player2Deck, victoryPile2);
		
		//hand values
		int hand1Value = hand1.back() % 13 + 1;
		int hand2Value = hand2.back() % 13 + 1;

		if (hand1Value == 1)
			hand1Value = 14;
		if (hand2Value == 1)
			hand2Value = 14;

		if (hand1Value != hand2Value)
		{
			//print card
			cout << "Player 1: " << "\tDeck: " << player1Deck.size() + hand1.size() << " \tPile: " << victoryPile1.size() << endl;
			printHand(hand1);
			cout << "Player 2: " << "\tDeck: " << player2Deck.size() + hand2.size() << " \tPile: " << victoryPile2.size() << endl;
			printHand(hand2);

			cout << "The winner is " << (hand1Value > hand2Value ? "Player 1" : "Player 2") << endl;
			cout << "Cards added to " << (hand1Value > hand2Value ? "Player 1" : "Player 2") << "'s pile." << endl;
		}
		else
		{
			do
			{
				cout << "Player 1: ";

				if (warHand(hand1, player1Deck, victoryPile1))
				{
					endGame = true;
					cout << endl << endl << "Player 2: ";
					warHand(hand2, player2Deck, victoryPile2);
					break;
				}

				cout << endl << endl << "Player 2: ";

				if(warHand(hand2, player2Deck, victoryPile2))
				{
					endGame = true;
					break;
				}

				hand1Value = hand1.back() % 13 + 1;
				hand2Value = hand2.back() % 13 + 1;

				cout << endl << endl;

				if (hand1Value != hand2Value)
				{
					cout << "The winner is " << (hand1Value > hand2Value ? "Player 1" : "Player 2") << endl;
					cout << "Cards added to " << (hand1Value > hand2Value ? "Player 1" : "Player 2") << "'s pile." << endl;
					break;
				}

				system("cls");

			} while (true);
		}

		if (!endGame)
		{
			if (hand1Value > hand2Value)
			{
				for (size_t i = 0; i < hand1.size(); i++)
				{
					victoryPile1.push_back(hand1.at(i));
					victoryPile1.push_back(hand2.at(i));
				}
				hand1.erase(hand1.begin(), hand1.end());
				hand2.erase(hand2.begin(), hand2.end());
			}
			else
			{
				for (size_t i = 0; i < hand2.size(); i++)
				{
					victoryPile2.push_back(hand2.at(i));
					victoryPile2.push_back(hand1.at(i));
				}
				hand1.erase(hand1.begin(), hand1.end());
				hand2.erase(hand2.begin(), hand2.end());
			}
		}
		

		if (refillDeck(player1Deck, victoryPile1))
		{
			cout << endl << endl << endl;
			cout << "Player 1 is out of cards." << endl << endl;
			cout << "Player 2 has won the game." << endl << endl << endl << endl;
			break;
		}
		if(refillDeck(player2Deck, victoryPile2))
		{
			cout << endl << endl << endl;
			cout << "Player 2 is out of cards." << endl << endl;
			cout << "Player 1 has won the game." << endl << endl << endl << endl;
			break;
		}

		cout << endl;
		system("pause");
		system("cls");
	} while (true);
	system("pause");
	system("cls");
}

bool warHand(vector<int>& hand, vector<int>& deck, vector<int>& pile)
{
	cout << "\tDeck: " << deck.size() + hand.size() << " \tPile: " << pile.size() << endl;

	printValue(hand.front());

	if (refillDeck(deck, pile))
	{
		cout << endl << "Out of cards." << endl;
		return true;
	}
	hand.push_back(deck.front());
	deck.erase(deck.begin());

	for (size_t i = 0; i < hand.size() - 1; i++)
	{
		cout << FACE_DOWN << " ";
	}

	cout << " ";

	if (refillDeck(deck, pile))
	{
		cout << endl << "Out of cards." << endl;
		return true;
	}
	hand.push_back(deck.front());
	deck.erase(deck.begin());

	printValue(hand.back());

	cout << endl;

	printSuit(hand.front());

	for (size_t i = 0; i < hand.size() - 2; i++)
	{
		cout << NO_SUIT << " ";
	}

	cout << " ";

	printSuit(hand.back());

	return false;
}

//jackBlack
/*
In the game of Black Jack, players start with 2 standard playing cards, and must decide to “hit”
(draw another card) or “stay” (keep their hand unchanged) in order to get the value of their hand
as close to 21 without going over. Players compete against the “house” or “dealer” by trying to 
have the hand closest to 21.

Face cards (jack, queen, and king) must have a value of 10. The Ace should have a value of 1 or 11, 
depending on which value is more useful (i.e. doesn’t increase the hand total over 21).

All of the player’s cards should be visible at all times. One of the dealer’s cards should remain 
hidden until the end of the player’s turn (at which point it is revealed).

The dealer must hit until the cards total 17 or more points (the dealer also hits on a “soft” 17,
i.e. a hand containing an ace, and one or more other cards totaling six).

If the final total of both the player’s and dealer’s hands have equal totals, the result should be 
a “push” (tie). If either the dealer or the player exceeds 21, they “bust” and the opponent wins.

Make the program ask if the player would like to play again, and loop until the answer is no.

BONUS: Implement wagers, and research and implement the rules for the “double down” action.

BONUS: Implement wagers, and research and implement the rules for the “split” action.

I will be checking COMMENTS, WHITESPACE USE, PROPER NAMING CONVENTIONS, and ERROR CHECKING.

*/

void blackJack(vector<int>& hand1, vector<int>& hand2, vector<int>& deck)
{
	system("cls");
	int dealerHandTotal;
	bool stay = false;
	int userInput = 0;

	hand1.erase(hand1.begin(), hand1.end());
	hand2.erase(hand2.begin(), hand2.end());

	//starting hand
	for (int i = 0; i < 2; i++)
	{
		hand1.push_back(drawCard(hand1, deck));
		if (i == 0)
			dealerHandTotal = blackJackCheck(hand1);
		hand2.push_back(drawCard(hand2, deck));
	}

	cout << "Dealer: " << "\tTotal: " << dealerHandTotal << " + ?" << endl;
	for (size_t i = 0; i < hand1.size() - 1; i++)
	{
		printValue(hand1.at(i));
	}
	cout << FACE_DOWN << " " << endl;
	for (size_t i = 0; i < hand1.size() - 1; i++)
	{
		printSuit(hand1.at(i));
	}
	cout << NO_SUIT << endl << endl;

	cout << endl << "Player: " << "\tTotal: " << blackJackCheck(hand2) << endl;
	printHand(hand2);

	do
	{
		if (blackJackCheck(hand2) == 21)
		{
			break;
		}

		cout << "[1] Hit" << endl;
		cout << "[2] Stay" << endl;
		cout << "[0] Quit" << endl;
		if (!(cin >> userInput))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			system("cls");
			continue;
		}
		if (userInput <0 || userInput>2)
		{
			system("cls");
			continue;
		}

		if (userInput == 1)
		{
			hand2.push_back(drawCard(hand2, deck));
			system("cls");
		}
		else if (userInput == 2)
		{
			stay = true;
			do
			{
				system("cls");
				blackJackPrintHands(hand1, hand2);

				if (blackJackCheck(hand1) <= 17)
				{
					cout << endl << "Dealer hits." << endl << endl;
					hand1.push_back(drawCard(hand1, deck));
					dealerHandTotal = blackJackCheck(hand1);
				}
				else
				{

					cout << endl << "Dealer stays." << endl << endl;
					break;
				}

				system("pause");

			} while (true);

		}
		else if (userInput == 0)
		{
			system("cls");
			return;
		}
		
		dealerHandTotal = blackJackCheck(hand1);

		if (blackJackCompare(hand1, hand2))
		{
			system("cls");
			blackJackPrintHands(hand1, hand2);
			break;
		}

		if (stay)
		{
			break;
		}

		//////////////////////////

		system("cls");

		blackJackPrintHands(hand1, hand2);

	} while (true);

	cout << endl << endl;
	if (!blackJackCompare(hand1, hand2))
	{
		if (blackJackCheck(hand1) > blackJackCheck(hand2) && blackJackCheck(hand1) < 21)
		{
			cout << "Dealer got closest." << endl << endl << "Dealer wins." << endl << endl;
		}
		else if (blackJackCheck(hand2) > blackJackCheck(hand1) && blackJackCheck(hand2) < 21)
		{
			cout << "Player got closest." << endl << endl << "Player wins." << endl << endl;
		}
	}

	system("pause");
	system("cls");
}

void blackJackPrintHands(vector<int>& hand1, vector<int>& hand2)
{
	cout << "Dealer: " << "\tTotal: " << blackJackCheck(hand1) << endl;
	printHand(hand1);

	cout << endl << "Player: " << "\tTotal: " << blackJackCheck(hand2) << endl;
	printHand(hand2);
}

int blackJackCheck(vector<int>& hand)
{
	int total = 0;
	int aces = 0;
		
	for (size_t i = 0; i < hand.size(); i++)
	{
		int x = hand.at(i) % 13 + 1;
		if (x == 11 || x == 12 || x == 13)
		{
			x = 10;
		}
		if (x == 1)
		{
			aces += 1;
			x = 0;
		}
		
		total += x;
	}

	for (int i = 0; i < aces; i++)
	{
		if (total + 11 <= 21 - (aces - 1))
		{
			total += 11;
		}
		else
		{
			total += 1;
		}
				
	}

	return total;
}

bool blackJackCompare(vector<int>& hand1, vector<int>& hand2)
{
	if (blackJackCheck(hand1) == 21 && blackJackCheck(hand2) != 21)
	{
		cout << "Dealer got 21." << endl << endl << "Dealer wins." << endl << endl;
		return true;
	}
	else if (blackJackCheck(hand2) == 21 && blackJackCheck(hand1) != 21)
	{
		cout << "Player got 21." << endl << endl << "Player wins." << endl << endl;
		return true;
	}
	else if (blackJackCheck(hand1) == blackJackCheck(hand2))
	{
		cout << "Game ends in a push." << endl << endl << "No winner." << endl << endl;
		return true;
	}
	else if (blackJackCheck(hand1) <= 21 && blackJackCheck(hand2) > 21)
	{
		cout << "Player got a bust." << endl << endl << "Dealer wins." << endl << endl;
		return true;
	}
	else if (blackJackCheck(hand2) <= 21 && blackJackCheck(hand1) > 21)
	{
		cout << "Dealer got a bust." << endl << endl << "Player wins." << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}


//Card management
bool refillDeck(vector<int>& deck, vector<int>& pile)
{
	if (deck.size() == 0)
	{
		if (pile.size() == 0)
		{
			return true;
		}
		for (size_t i = 0; i < pile.size(); i++)
		{
			deck.push_back(pile.at(i));
		}
		pile.erase(pile.begin(), pile.end());
	}
	return false;
}

int handTotal(vector<int>& hand)
{
	int total = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		total += hand.at(i) % 13 + 1;
	}
	return total;
}

int drawCard(vector<int>& handGive, vector<int>& deck)
{
	int randomCard = deck.at(1);

	deck.erase(deck.begin());

	return randomCard;
}

void sortHand(vector<int>& hand) 
{
	int temp;
	for (size_t i = 0; i < hand.size(); i++){
		for (size_t j = i + 1; j< hand.size(); j++){
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
	for (size_t i = 0; i < hand.size(); i++)
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
	for (size_t i = 0; i < hand.size(); i++)
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

void printValue(int i)
{
	//print card value
		if (i % 13 == 0)
		{
			cout << "A" << " ";
		}
		else if (i % 13 == 10)
		{
			cout << "J" << " ";
		}
		else if (i % 13 == 11)
		{
			cout << "Q" << " ";
		}
		else if (i % 13 == 12)
		{
			cout << "K" << " ";
		}
		else
		{
			cout << (i % 13) + 1 << " ";
		}
		if ((i % 13) + 1 != 10)
			cout << " ";
}

void printSuit(int i)
{
	char asciiChar;
	//print card suit
	if (i / 13 == 0)
	{
		asciiChar = HEART;
	}
	else if (i / 13 == 1)
	{
		asciiChar = DIAMOND;
	}
	else if (i / 13 == 2)
	{
		asciiChar = CLUB;
	}
	else if (i / 13 == 3)
	{
		asciiChar = SPADE;
	}
	cout << asciiChar << "  ";
}