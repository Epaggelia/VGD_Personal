#include <iostream>

using std::cout;
using std::endl;

#ifndef CARD_TYPE_H
#define CRAD_TYPE_H

class CardType
{
private:
	int _rank;
	char _suit;
public:
	CardType(int rank, char suit);

	void setCard(int rank, char suit);
	int rank();
	char suit();
	void show();
};

#endif