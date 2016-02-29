#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>
#include "utilities.h"
#include "Card.h"

using namespace std;

Card::Card()
{
	invalid = true;
}

Card::Card(Suit s, Rank r)
{
	initialize(s, r);
	invalid = false;
}


void Card::initialize(Suit s, Rank r)
{
	suit = s;
	rank = r;
	invalid = false;
}

Suit Card::getSuit()
{
	return suit;
}

Rank Card::getRank()
{
	return rank;
}

string Card::toString()
{
	if (invalid)
	{
		return "Invalid card!";
	}
	else
	{
		return rankToString(rank) + " of " + suitToString(suit);
	}
}

string Card::toStringShort()
{
	if (invalid)
	{
		return "Invalid card!";
	}
	else
	{
		string suitString = suitToString(suit).substr(0, 1);
		string rankString = intToString(rank + 2);
		return suitString + rankString;
	}
}

