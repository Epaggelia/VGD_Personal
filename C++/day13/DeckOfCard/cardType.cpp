#include "cardType.h"

CardType::CardType(int rank, char suit)
{
	if (rank < 1 || rank > 13)
	{
		_rank = 1;
	}
	else
	{
		_rank = rank;
	}
	if (suit != 3 && suit != 4 && suit != 5 && suit != 6)
	{
		_suit = 1;
	}
	else
	{
		_suit = suit;
	}
}

void CardType::setCard(int rank, char suit)
{
	if (rank < 1 || rank > 13)
	{
		_rank = 1;
	}
	else
	{
		_rank = rank;
	}
	if (suit != 3 && suit != 4 && suit != 5 && suit != 6)
	{
		_suit = 1;
	}
	else
	{
		_suit = suit;
	}
}

int CardType::rank()
{
	return _rank;
}

char CardType::suit()
{
	return _suit;
}

void CardType::show()
{
	cout << _rank << _suit;
}