#pragma once
#include <string>

using namespace std;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank {
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING, ACE
};

struct cardStruct { Suit s; Rank r; };

//Functions
string toStringShort(cardStruct card);
string intToString(int number);
string toString(cardStruct card);
string rankToString(Rank rank);
string suitToString(Suit suit);
int randomWithLimits(int min, int max);

