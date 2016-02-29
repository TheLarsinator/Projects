#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

int randomWithLimits(int min, int max)
{
	int i;
	do
	{
		i = rand();
	} while (i < min || i > max);

	return i;
}
void incrementByValueNumTimes(int *startValue, int increment, int numTimes) 
{
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

void swapNumbers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void randomizeArray(int *liste, int length)
{
	for (int i = 0; i < length; i++)
	{
		liste[i] = randomWithLimits(0, 100);
	}
}

void printArray(int *liste, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << liste[i];
	}
	cout << endl << endl;

}

void sortArray(int *array, int length)
{
	for (int i = 1; i < length; i++)
	{
		int j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			swapNumbers(&array[j - 1], &array[j]);
			j--;
		}
	}
}

double medianOfArray(int *array, int length)
{
	if (length % 2 == 0)
	{
		return (array[length / 2] + array[length / 2 + 1]) / 2;
	}
	else
	{
		return array[(length + 1) / 2];
	}
}

void randomizeCString(char *array, int size, char min, char max)
{
	for (int i = 0; i < size - 1; i++)
	{
		array[i] = randomWithLimits(min, max);
	}
	array[size - 1] = '\0';
}

void readInputToCString(char *array, int size, char min, char max)
{
	for (int i = 0; i < size - 1; i++)
	{
		char a = max +1;
		while (a < min || a > max)
		{
			cout << "Skriv inn en verdi mellom " << min << " og " << max << endl;
			cin >> a;
		}
		array[i] = a;
	}
	array[size - 1] = '\0';
}

int countOccurencesOfCharacter(char *array, int size, char a)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == a)
			total++;
	}
	return total;
}

