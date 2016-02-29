// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
void print(string a)
{
	std::cout << a << std::endl;
}


int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	print("Fibonacci numbers:");
	for (int i = 1; i < n; i++)
	{
		int temp = b;
		b = a + b;
		a = temp;
		cout << i << ", " << b << endl;
	}
	print("----");
	return b;
}

void triangleNumbersBelow(int n)
{
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc + num < n)
	{
		acc = acc + num;
		num += 1;
		cout << acc << endl;
	}
	print("----");
}

bool isTriangleNumber(int number)
{
	int acc = 1;
	while (number < 0)
	{
		number -= acc;
		acc += 1;
	}
	if (number == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int squareNumberSum(int n)
{
	int totalSum = 0;
	for (int i = 0; i < n; i++)
	{
		totalSum += i*i;
		cout << i*i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

int max(int a, int b)
{
	if (a < b)
	{
		cout << "A is greater than B" << endl;
		return a;
	}
	else
	{
		cout << "B is greater than A" << endl;
		return b;
	}
}

bool isPrime(int n)
{
	bool primeness = true;
	for (int j = 2; j < n; j++)
	{
		if (n % j == 0)
		{
			primeness = false;
			break;
		}
	}
	return primeness;
}

void naivePrimeNumberSearch(int n)
{
	for (int number = 2; number < n; number++)
	{
		if (isPrime(number))
		{
			cout << number << " is a prime number!" << endl;
		}
	}
}

int findGreatestDivisor(int n)
{
	for (int divisor = n-1; divisor > 0; divisor--)
	{
		if (n % divisor == 0)
		{
			return divisor;
		}
	}
	return 0;
}

void compareListofNumbers(int l[])
{
	int r [3] = {0, 0, 0};
	for (int i = 0; i < sizeof(l); i++)
	{
		if (l[i] < 0)
		{
			r[0] += 1;
		}
		else if (l[i] == 0)
		{
			r[1] += 1;
		}
		else if (l[i] > 0)
		{
			r[2] += 1;
		}
	}
	cout << r[0] << " numbers were below zero!" << endl;
	cout << r[1] << " numbers were zero!" << endl;
	cout << r[2] << " numbers were greater than zero!" << endl;
}

int testingFor()
{
	for (int i = 0; i < 100; i += 2)
	{
		cout << i << endl;
	}
	return 0;
}

int main()
{
	system("chcp 1252");
	print("Hello world!");
	fibonacci(5);
	triangleNumbersBelow(5);
	cout << isTriangleNumber(5) << endl;
	print("----");
	squareNumberSum(5);
	print("----");
	max(4, 7);
	print("----");
	cout << isPrime(5) << endl;
	print("----");
	naivePrimeNumberSearch(10);
	print("----");
	cout << findGreatestDivisor(15) << endl;
	print("----");
	int k [15] = { 1, 2, 3, 4, 5, 6, -1, -3, 0, 0, 0, -4, -9, 2, 1 };
	compareListofNumbers(k);
	print("----");
	//testingFor();
	//cin.get();
    return 0;
}