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
const int HAND_COUNT = 5;

void menu();
void createCards(vector<CardType>& deck);
void dealHand(vector<CardType>& deck, vector<CardType*>& hand);
void showHand(vector<CardType*>& hand);

int main()
{
	srand(static_cast<unsigned int> (time(0)));
	menu();
	return 0;
}

void menu()
{
	vector<CardType>deck;
	vector<CardType*> hand;

	createCards(deck);

	do
	{
		int choice = 0;

		cout << "[1] Show hand." << endl;
		cout << "[2] Deal hand." << endl;
		cout << "[3] Quit." << endl;
		cout << "> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			showHand(hand);
			break;
		case 2:
			dealHand(deck, hand);
			break;
		case 3:
			return;
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

void dealHand(vector<CardType>& deck, vector<CardType*>& hand)
{
	hand.clear();

	for (size_t i = 0; i < HAND_COUNT; i++)
	{
		int cardIndex = rand() % DECK_COUNT;

		CardType card(deck[cardIndex].rank(), deck[cardIndex].suit());

		do
		{
			bool found = false;
			for (int j = 0; j < hand.size(); j++)
			{
				if (hand[j]->rank() == card.rank() && hand[j]->suit() == card.suit())
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
			card = CardType(deck[cardIndex].rank(), deck[cardIndex].suit());
		} while (true);
		hand.push_back(&deck[cardIndex]);
	}

	for (int i = 0; i < hand.size(); i++)
	{
		for (int j = 0; j < hand.size(); j++)
		{
			if (hand[i]->rank() > hand[i + 1]->rank())
			{
				if (hand[i]->rank() > hand[i + 1]->rank())
				{
					if (hand[i]->suit() > hand[i + 1]->suit())
					{
						int tempRank = hand[i] -> rank(); 
						char tempSuit = hand[i] -> suit();
						hand[i]->setCard(hand[j]-> rank(), hand[j]->suit());;
						hand[j]->setCard(tempRank, tempSuit);
					}
				}
				else
				{
					int tempRank = hand[i]->rank();
					char tempSuit = hand[i]->suit();
					hand[i]->setCard(hand[j]->rank(), hand[j]->suit());;
					hand[j]->setCard(tempRank, tempSuit);
				}

			}
		}
	}
}

void showHand(vector<CardType*>& hand)
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
		cout << endl;
	}
}
