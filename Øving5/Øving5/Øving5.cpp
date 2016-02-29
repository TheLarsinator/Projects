// Øving5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include "utilities.h"
#include <string>
#include "CardDeck.h"
#include "Card.h"
#include "BlackJack.h"

using namespace std;

int main()
{
	srand(time(NULL));
	BlackJack blackjack;
	CardDeck deck;
	string answer;
	do
	{
		cout << "Do you want to play with bets? Y = yes, N = no" << endl;
		cin >> answer;
	} while (answer != "N" && answer != "Y");
	if (answer == "Y")
		blackjack.playBlackJackWithBets(deck);
	else
	{
		bool firstRound = true;
		do
		{
			blackjack.playGame(deck, firstRound);
			firstRound = false;
			do
			{
				cout << "Do you want to play another round? Y = yes, N = no" << endl;
				cin >> answer;
			} while (answer != "N" && answer != "Y");
			if (answer == "Y")
			{
				for (int i = 0; i < 5; i++)
					cout << endl;
			}
		} while (answer == "Y");
	}
    return 0;
}

