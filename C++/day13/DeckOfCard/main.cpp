#include "cardType.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::rand;
using std::cin;

enum CARD_SUIT { HEART, DIAMOND, CLUB, SPADE };

const int DECK_COUNT = 52;
const int hand_COUNT = 5;

void menu();
void createCards(vector<CardType>& deck);
void dealhand(vector<CardType>& deck, vector<CardType*>& hand);
void showhand(vector<CardType*>& hand);
int whichhand();

int main()
{
	srand(static_cast<unsigned int> (time(0)));
	menu();
	return 0;
}

void menu()
{
	vector<CardType> deck;
	vector<CardType*> hand;
	vector<CardType*> hand2;

	createCards(deck);

	do
	{
		int choice = 0;

		cout << "[1] Show hand." << endl;
		cout << "[2] Deal hand." << endl;
		cout << "[3] Quit." << endl;
		cout << "> ";
		cin >> choice;

		if (choice == 3)
			return;

		int handNumber = whichhand();

		if (handNumber == 3)
		{
			continue;
		}

		switch (choice)
		{
		case 1:
			if (handNumber == 1)
				showhand(hand);
			else
				showhand(hand2);
			break;
		case 2:
			if (handNumber == 1)
				dealhand(deck, hand);
			else
				dealhand(deck, hand2);
			break;
		default:
			cout << "Invalid option." << endl;
		}
	} while (true);
}

void createCards(vector<CardType>& deck)
{
	for (size_t s = 0; s < 4; s++)
	{
		for (size_t r = 0; r < 13; r++)
		{
			switch (s)
			{
			case HEART:
				deck.push_back(CardType(r, 3));
				break;
			case DIAMOND:
				deck.push_back(CardType(r, 4));
				break;
			case CLUB:
				deck.push_back(CardType(r, 5));
				break;
			case SPADE:
				deck.push_back(CardType(r, 6));
				break;
			}
		}
	}
}

void dealhand(vector<CardType>& deck, vector<CardType*>& hand)
{
	hand.clear();

	for (size_t i = 0; i < hand_COUNT; i++)
	{
		int cardIndex = rand() % DECK_COUNT;

		CardType card(deck[cardIndex].value(), deck[cardIndex].suit());

		do
		{
			bool found = false;
			for (int j = 0; j < hand.size(); j++)
			{
				if (hand[j]->value() == card.value() && hand[j]->suit() == card.suit())
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				break;
			}

			cardIndex = rand() % DECK_COUNT;
			card = CardType(deck[cardIndex].value(), deck[cardIndex].suit());
		} while (true);
		hand.push_back(&deck[cardIndex]);
	}
}

void showhand(vector<CardType*>& hand)
{
	if (hand.size() == 0)
	{
		cout << "You have no cards" << endl << endl;
	}
	else
	{
		cout << "Your cards: ";
		for (size_t i = 0; i < hand.size(); i++)
		{
			hand[i]->show();
			cout << " ";
		}
		cout << endl << endl;
	}
}

int whichhand()
{
	int choice = 0;

	do
	{
		cout << endl << "Which hand will you choose?" << endl;
		cout << endl;
		cout << "[1] Player 1" << endl;
		cout << "[2] Player 2" << endl;
		cout << "[3] Return" << endl;
		cout << "> ";
		cin >> choice;
		cout << endl;

		if (choice != 1 && choice != 2 && choice != 3)
		{
			cout << "Invalid option." << endl;
		}
		else
		{
			break;
		}
	} while (true);

	return choice;
}