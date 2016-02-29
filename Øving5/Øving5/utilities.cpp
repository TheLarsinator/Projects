#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include "utilities.h"
#include <string>
#include <sstream>
using namespace std;

int randomWithLimits(int min, int max)
{
	int i;
	do
	{
		i = rand();
	} while (i < min || i > max);

	return i;
}

string suitToString(Suit suit)
{
	switch (suit)
	{
	case CLUBS:
		return "Clubs";
	case DIAMONDS:
		return "Diamonds";
	case HEARTS:
		return "Hearts";
	case SPADES:
		return "Spades";
	}
}

string rankToString(Rank rank)
{
	switch (rank)
	{
	case TWO:
		return "Two";
	case THREE:
		return "Three";
	case FOUR:
		return "Four";
	case FIVE:
		return "Five";
	case SIX: 
		return "Six";
	case SEVEN: 
		return "Seven";
	case EIGHT: 
		return "Eight";
	case NINE:
		return "Nine";
	case TEN:
		return "Ten";
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	case ACE:
		return "Ace";
	}
}

string toString(cardStruct card)
{
	Suit suit = card.s;
	Rank rank = card.r;

	string suitString = suitToString(suit);
	string rankString = rankToString(rank);

	return rankString + " of " + suitString;
}

string intToString(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

string toStringShort(cardStruct card)
{
	Suit suit = card.s;
	Rank rank = card.r;

	string suitString = suitToString(suit).substr(0, 1);
	string rankString = intToString(rank + 2);
	return suitString + rankString;
}