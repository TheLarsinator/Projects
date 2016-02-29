// Øving7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

void fillInFibonacciNumber(int result[], int length)
{
	int a = 0;
	int b = 1;
	int temp;

	for (int i = 0; i < length; i++)
	{
		if (i == 0)
			result[i] = 0;
		else if (i == 1)
			result[i] = 1;
		else
		{
			result[i] = a + b;
			temp = a;
			a = b;
			b += temp;
		}
	}
}

void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}

void createFibonacci()
{
	cout << "How many fibonacci numbers do you need?" << endl;
	int n;
	cin >> n;
	int *results = new int[n] {};
	fillInFibonacciNumber(results, n);
	printArray(results, n);
	delete[] results;
	results = nullptr;
}

int main()
{
	int results[10];
	int length = 10;
	createFibonacci();
	system("pause");
    return 0;
}

