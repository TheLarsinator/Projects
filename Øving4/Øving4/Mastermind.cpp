#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "utilities.h"
#include <algorithm>

using namespace std;

int checkCharactersAndPosition(char code[], char guess[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		if (code[i] == guess[i])
		{
			total++;
		}
	}
	return total;
}

int checkCharacters(char code[], char guess[], int size, int letters)
{
	int total = 0;
	int a;
	int b;
	for (int i = 'A'; i < 'A' + letters - 1; i++)
	{
		a = countOccurencesOfCharacter(code, size, i);
		b = countOccurencesOfCharacter(guess, size, i);
		total += min(a, b);
	}
	return total;
}

void playMastermind()
{
	const int SIZE = 4;
	const int LETTERS = 6;
	const int ATTEMPTS = 10;

	char code[SIZE + 1] = { 'A', 'A', 'A', 'A', '\0' };
	char guess[SIZE + 1] = { 'B', 'A', 'A', 'A', '\0' };

	randomizeCString(code, SIZE + 1, 'A', 'A' + LETTERS - 1);

	cout << code << endl;
	int playedAttempts = 1;
	do 
	{
		cout << "Attempt " << playedAttempts << endl;
		readInputToCString(guess, SIZE+1, 'A', 'A' + LETTERS - 1);
		int sign = checkCharacters(code, guess, SIZE, LETTERS);
		int correct = checkCharactersAndPosition(code, guess, SIZE);
		cout << "Antall på riktig plass: " << correct << endl;
		cout << "Antall riktige tegn: " << sign - correct << endl;
		playedAttempts++;
	} while (checkCharactersAndPosition(code, guess, SIZE) < SIZE && playedAttempts <= ATTEMPTS);

	if (checkCharactersAndPosition(code, guess, SIZE) < SIZE)
	{
		cout << "DU ER EN TAPER!" << endl;
		cout << "Koden var: " << code << endl;
	}
	else
	{
		cout << "Gratulerer, du vant på: " << playedAttempts << " forsøk!" << endl;
	}
}