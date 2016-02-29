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

//int modernRandomWithLimit(int min, int max, default_random_engine& engine)
//{
//	uniform_int_distribution<int> uniform(min, max);
//	return uniform(engine);
//	return 0;
//}