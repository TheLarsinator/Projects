#include <iostream>
#include "Image.h"
#include "Vector.h"
#include "Matrix.h"
#include "stdafx.h"
//inkluder andre headerfiler du lager
using namespace std;

int main()
{
	Matrix matrise(4, 4, 12);
	Vector vektor(3);

	vektor.set(1, 1);
	vektor.set(2, 2);
	vektor.set(3, 2);

	Vector result = (matrise * vektor);
	return 0;
}
