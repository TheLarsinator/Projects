#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include "utilities.h"


using namespace std;

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	std::cout << "v0: " << v0;
	incrementByValueNumTimes(&v0, increment, iterations);
	std::cout 
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << v0 << std::endl;
}

void testTablesSorting()
{
	int percentages[20] = {};
	int median;
	printArray(percentages, 20);
	randomizeArray(percentages, 20);
	printArray(percentages, 20);
	swapNumbers(&percentages[0], &percentages[1]);
	printArray(percentages, 20);
	median = medianOfArray(percentages, 20);
	cout << "median: " << median << endl << endl;
	sortArray(percentages, 20);
	printArray(percentages, 20);
	median = medianOfArray(percentages, 20);
	cout << "median: " << median << endl;
}

void testCStrings()
{
	const int gradesAmount = 40;
	char grades[gradesAmount+1] = "";//+ 1 for å ha plass til en 0
	int gradeCount[6] = {};
	randomizeCString(grades, gradesAmount+1, 'A', 'F');
	cout << grades << endl;
	//readInputToCString(grades, gradesAmount+1, 'A', 'F');
	//cout << grades << endl;
	char a = 'A';
	for (int i = 0; i < 6; i++)
	{
		gradeCount[i] = countOccurencesOfCharacter(grades, gradesAmount+1, a + i);
	}
	printArray(gradeCount, 6);
	int total = 0;
	double average;
	for (int i = 0; i < 6; i++)
	{
		total += gradeCount[i] * (i + 1);
	}
	average = total / gradesAmount;
	cout << round(average) << endl;
	cout << (char)('A' + round(average) - 1) << endl;

}