// CPPTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	cout << "Press any key! CTRL-D to end" << endl;
	while (1)
	{
		unsigned char x = _getch();
		if (0 == x)
		{
			printf("Function key!\n");
			x = _getch();
		}
		printf("key = %02x\n", x);
		if (x == 4) break;
	}


	return 0;
}