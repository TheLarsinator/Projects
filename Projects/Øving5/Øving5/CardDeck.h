#pragma once
#include "Card.h"

class CardDeck
{
private:
	Card cards[52];
	int currentCardIndex;
	void swap(int i, int j);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();


};