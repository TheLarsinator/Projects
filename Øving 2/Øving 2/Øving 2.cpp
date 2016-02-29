// Øving 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void inputAndPrintInteger()
{
	int tall;
	cout << "Skriv et heltall: " << endl;
	cin >> tall;
	cout << "Du skrev dette: " << tall << endl;
}

int inputInteger()
{
	int tall;
	cout << "Skriv et heltall: " << endl;
	cin >> tall;
	return tall;
}

void inputIntegersAndPrintSum()
{
	//Bruker inputInteger siden denne returnerer inputten
	int a = inputInteger();
	int b = inputInteger();
	cout << "Summen er: " << a + b << endl;
}

bool isOdd(int i)
{
	if (i % 2 == 0)
		return false;
	else
		return true;
}

void printHumanReadableTime(int sec)
{
	int	timr = sec % 3600;
	int tim = (sec - timr) / 3600;
	int minr = timr % 60;
	int min = (timr - minr) / 60;

	cout << tim << "timer, " << min << "minutter, " << minr << "sekunder." << endl;
}

void inputIntegersUsingLoopAndPrintSum()
{
	int total = 0;
	int amount;
	cout << "Hvor mange tall skal legges sammen?" << endl;
	cin >> amount;
	//Her passer en for løkke, ellers kunne jeg ha brukt en while løkke som sjekket om en variabel ble 0
	for (int i = 0; i < amount; i++)
	{
		total += inputInteger();
	}
	cout << "Totalen blir: " << total << endl;
}

double inputDouble()
{
	double tall;
	cout << "Skriv inn et desimaltall: " << endl;
	cin >> tall;
	return tall;
}

void changeNokToEur()
{
	double nok = -1;
	while(nok < 0)
		nok = inputDouble();
	double eur = nok / 9.64;
	cout.precision(2);
	cout << nok << " kroner tilsvarer: €" << fixed << eur << endl;
}

void printTable()
{
	int height;
	int width;
	cout << "Høyde: " << endl;
	cin >> height;
	cout << "Bredde" << endl;
	cin >> width;

	for (int i = 1; i < height+1; i++)
	{
		for (int j = 1; j < width+1; j++)
		{
			cout << i*j << "\t";
		}
		cout << endl;
	}
}

double discriminant(double a, double b, double c)
{
	return (b*b - 4 * a*c);
}

void printRealRoots(double a, double b, double c)
{
	double disc = discriminant(a, b, c);
	if (disc > 0)
	{
		double sol1 = (-b + sqrt(disc)) / 2 * a;
		double sol2 = (-b - sqrt(disc)) / 2 * a;
		cout << "Solutions are: " << sol1 << " and " << sol2 << endl;
	}
	else if (disc == 0)
	{
		double sol1 = -b / (2 * a);
		cout << "Solution is: " << sol1 << endl;
	}
	else
	{
		cout << "No real roots!" << endl;
	}
}

void solveQuadraticEquation()
{
	double a;
	double b;
	double c;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	printRealRoots(a, b, c);
}

void calculateLoanPayments()
{
	int rente;
	cout << "Renter: ";
	cin >> rente;
	
	int loanSize;
	cout << "Total lånebeløp: ";
	cin >> loanSize;

	int avdrag;
	cout << "Antall avdrag: ";
	cin >> avdrag;
	
	cout << "År \t \t" << "Innbetaling \t" << "Gjennstående lån" << endl;
	int remainingLoan = loanSize;
	int payment;
	for (int i = 0; i < avdrag; i++)
	{
		payment = loanSize / avdrag + rente / 100 * remainingLoan;
		remainingLoan -= payment;
		cout << i+1 << "\t \t" << payment << "\t \t" << remainingLoan << endl;
	}
}
int main()
{
	/*inputAndPrintInteger();
	cout << "Du skrev: " << inputInteger() << endl;
	inputIntegersAndPrintSum();

	for (int i = 0; i < 10; i++)
	{
		if (isOdd(i))
			cout << i << " er et oddetall!" << endl;
		else
			cout << i << " er ikke et oddetall!" << endl;
	}

	printHumanReadableTime(10000);

	inputIntegersUsingLoopAndPrintSum(4);

	inputDouble();
	
	changeNokToEur();
	*/
	int choice = -1;
	while (choice != 0)
	{
		cout << "0) Avslutt" << endl << "1) Summer to tall" << endl << "2) Summer flere tall" << endl << "3) Koverter NOK til EUR" << endl << "4) Løs andregradsligning" << endl  << "5) Regn ut innbetalinger til lån" << endl << "Angi valg 0-5:" << endl;
		cin >> choice;

		if (choice == 1)
		{
			inputIntegersAndPrintSum();
		}
		else if (choice == 2)
		{
			inputIntegersUsingLoopAndPrintSum();
		}
		else if (choice == 3)
		{
			changeNokToEur();
		}
		else if (choice == 4)
		{
			solveQuadraticEquation();
		}
		else if (choice == 5)
		{
			calculateLoanPayments();
		}
		else
		{
			cout << "Ikke et alternativ, prøv igjen!" << endl;
		}
	}
	printTable();
	


	int z;
	cin >> z;
	
    return 0;
}

