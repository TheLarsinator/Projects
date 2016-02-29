#pragma once
#include "utilities.h"

class Card
{
private:
	Suit suit;
	Rank rank;
	bool invalid;
public:
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	string toString();
	string toStringShort();
	Card();
	Card(Suit s, Rank r);
};