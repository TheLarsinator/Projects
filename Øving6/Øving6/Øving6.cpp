// Øving6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include "Matrix2x2.h"
#include <string>

using namespace std;
int main()
{
	double a, b, c, d, p, q;
	cout << "Enter the values: a, b, c, d, p, q" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> p;
	cin >> q;

	Matrix2x2 matrix(a, b, c, d);
	Vector2 vector(p, q);

	if (matrix.det() == 0)
	{
		cout << "Systemet har desverre ingen løsning..." << endl;
	}
	else
	{
		Matrix2x2 invMatrix = matrix;
		matrix.inverse(invMatrix);
		Vector2 result;
		result = invMatrix * vector;
		cout << "X = " << vector.getX() << "; Y = " << vector.getY() << endl;
	}
	system("pause");
    return 0;
}

