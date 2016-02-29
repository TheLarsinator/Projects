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
#include "BlackJack.h"


bool BlackJack::isAce(Card *card)
{
	if ((*card).getRank() == ACE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int BlackJack::getCardValue(Card *card)
{
	Rank rank = (*card).getRank();
	switch (rank)
	{
	case JACK:
		return 10;
		break;
	case QUEEN:
		return 10;
		break;
	case KING:
		return 10;
		break;
	case ACE:
		return -1;
		break;
	default:
		return rank + 2;
	}
}

int BlackJack::getPlayerCardValue(Card *card)
{
	int value = getCardValue(card);
	if (value != -1)
		return value;
	else
	{
		int aceValue = 0;
		cout << "Choose a value: 1 or 11: " << endl;
		do
		{
			cout << "Choose a value: 1 or 11: " << endl;
			cin >> aceValue;
			if (aceValue != 1 && aceValue != 11)
				cout << "Invalid ace value!" << endl;
		} while (aceValue != 1 && aceValue != 11);
		return aceValue;
	}
}

int BlackJack::getDealerCardValue(Card *card, int dealerHand)
{
	int value = getCardValue(card);
	if (value != -1)
		return value;
	else
	{
		if (dealerHand + 11 > 21)
			return 1;
		else
			return 11;
	}
}

bool BlackJack::askPlayerDrawCard()
{
	string answer;
	do
	{
		cout << "Do you want to draw another card? Y = yes, N = no" << endl;
		cin >> answer;
		if (answer == "Y")
			return true;
		else if (answer == "N")
			return false;
		else
			cout << "Invalid answer!" << endl;
	} while (answer != "Y" && answer != "N");
}

void BlackJack::drawInitialCards(CardDeck *deck)
{
	playerHand = 0;
	dealerHand = 0;
	(*deck).shuffle();
	//deck.print();
	for (int i = 0; i < 2; i++)
	{
		playerCards[i] = (*deck).drawCard();
		dealerCards[i] = (*deck).drawCard();

		playerHand += getPlayerCardValue(&playerCards[i]);
		dealerHand += getDealerCardValue(&dealerCards[i], dealerHand);
	}
	playerCardsDrawn = 2;
	dealerCardsDrawn = 2;
	cout << "Dealer's first card: " << dealerCards[0].toString() << endl;
	cout << "Your cards: " << endl << playerCards[0].toString() << endl << playerCards[1].toString() << endl;
}

void BlackJack::printIntroduction(bool withBets)
{
	cout << "Welcome to blackjack. You play against a dealer." << endl;
	if (withBets)
		cout << "Place your bets and try to stop before you go broke!" << endl;

	cout << "Good luck and have fun!" << endl;
}

bool BlackJack::playGame(CardDeck deck, bool firstGame)
{
	if(firstGame)
		printIntroduction(false);
	drawInitialCards(&deck); //Shuffles the deck, and draws the first cards.
	bool drawCard;
	do
	{
		drawCard = askPlayerDrawCard();
		if (drawCard)
		{
			playerCards[playerCardsDrawn] = deck.drawCard();
			cout << "You drew a: " << playerCards[playerCardsDrawn].toString() << endl;
			playerHand += getPlayerCardValue(&playerCards[playerCardsDrawn]);
			playerCardsDrawn++;
			if (playerHand > 21)
			{
				cout << "You lost..." << endl;
				return false;
			}
		}
		else
			break;
	} while (playerHand < 21);
	
	//cout << playerHand << endl; //debug
	//Now the player is finished playing, dealers turn

	cout << "Dealers cards: " << endl << dealerCards[0].toString() << endl << dealerCards[1].toString() << endl;
	//cout << dealerHand << endl; //debug

	while (dealerHand < 17)
	{
		dealerCards[dealerCardsDrawn] = deck.drawCard();
		cout << "The dealer drew a: " << dealerCards[dealerCardsDrawn].toString() << endl;
		dealerHand += getDealerCardValue(&dealerCards[dealerCardsDrawn], dealerHand);
		dealerCardsDrawn++;
		system("pause");
	}

	cout << "Playerscore: " << playerHand << endl;
	cout << "Dealerscore: " << dealerHand << endl;

	//Dealer should be done by now, lets see who won
	if (playerHand == 21)
	{
		cout << "Blackjack! You have won1" << endl;
		return true;
	}
	if (dealerHand > 21 && playerHand <= 21)
	{
		cout << "The dealer died. Congratulations, you have won!" << endl;
		return true;
	}
	else if (dealerHand == playerHand)
	{
		cout << "You score is the same as the dealer, so you have lost..." << endl;
		return false;
	}
	else if (playerHand <= 21 && playerHand > dealerHand)
	{
		cout << "You beat the dealer. Congratulations, you have won!" << endl;
		return true;
	}
	else if (dealerHand <= 21 && dealerHand > playerHand)
	{
		cout << "The dealer beat you. You lost..." << endl;
		return false;
	}
	else
	{
		cout << "Something goes wrong..." << endl;
	}
}

void BlackJack::playBlackJackWithBets(CardDeck deck)
{
	printIntroduction(true);
	BlackJack blackjack;
	string answer;
	int money = 100;
	int bet;
	bool victory;
	do
	{
		cout << "You have: $" << money << endl;
		do
		{
			cout << "Minimum $1 bets. Place your bets: ";
			cin >> bet;
		} while (bet < 1 || bet > money);

		victory = blackjack.playGame(deck, false); //We have already printed the introduction text
		if (victory)
			money += bet;
		else
			money -= bet;
		if (money < 1)
		{
			cout << "You are broke!" << endl;
			break;
		}

		system("pause");
		do
		{
			cout << "You now have $" << money << endl;
			cout << "Want to play another round? Y = yes, N = no" << endl;
			cin >> answer;
		} while (answer != "N" && answer != "Y");
		if (answer == "Y")
		{
			for (int i = 0; i < 5; i++)
				cout << endl;
		}
	} while (answer == "Y");

	if (money > 0)
		cout << "Congratulations, you left with $" << money << endl;
	system("pause");
}