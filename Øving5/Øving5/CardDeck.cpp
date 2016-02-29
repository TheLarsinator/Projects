#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>
#include "utilities.h"
#include "Card.h"
#include "CardDeck.h"


CardDeck::CardDeck()
{
	int cardNumber = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 13; k++)
			{
				cards[cardNumber] = Card(static_cast<Suit>(j), static_cast<Rank>(k));
				cardNumber++;
			}
		}
	currentCardIndex = 0;
}

void CardDeck::swap(int i, int j)
{
	Card temp = cards[i];
	cards[i] = cards[j];
	cards[j] = temp;
}

void CardDeck::print()
{
	for (int i = 0; i < 52; i++)
	{
		cout << cards[i].toString() << endl;
	}
}

void CardDeck::printShort()
{
	for (int i = 0; i < 52; i++)
	{
		cout << cards[i].toStringShort() << endl;
	}
}

void CardDeck::shuffle()
{
	for (int i = 0; i < 52 - 2; i++)
	{
		int j = randomWithLimits(0, 52 - i);
		swap(i, j);
	}
}

Card CardDeck::drawCard()
{
	currentCardIndex++;
	//cout << "Drawing card number: " << currentCardIndex << endl; //debug
	return cards[currentCardIndex - 1];
}