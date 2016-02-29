#pragma once
#include "Card.h"
#include "CardDeck.h"
class BlackJack
{
private:
	CardDeck deck;
	int playerHand;
	int dealerHand;
	int playerCardsDrawn;
	int dealerCardsDrawn;
	Card dealerCards[10];
	Card playerCards[10];
	void printIntroduction(bool withBets);
public:
	bool isAce(Card *card);
	int getCardValue(Card *card);
	int getPlayerCardValue(Card *card);
	int getDealerCardValue(Card *card, int dealerHand);
	bool askPlayerDrawCard();
	void drawInitialCards(CardDeck *deck);
	bool playGame(CardDeck deck, bool firstGame);
	void playBlackJackWithBets(CardDeck deck);
};