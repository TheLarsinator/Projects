// Øving4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tests.h"
#include <Windows.h>
#include <ctime>
#include "Mastermind.h"
#include <iostream>


using namespace std;
int main()
{
	setlocale(LC_ALL, "Norwegian");

	//Oppgave 1:
	//Den vil ikke endre verdien til v0...
	//testCallByValue();
	srand(time(NULL));

	//testTablesSorting();

	//testCStrings();
	//playMastermind();

	char a = '!';
	int b = a;
	char d = 'F';
	int c = d;
	cout << b << "\t" << c << endl;
	system("pause");
    return 0;
}

