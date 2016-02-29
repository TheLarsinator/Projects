#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include "Matrix2x2.h"
#include "Vector2.h"

using namespace std;

double Matrix2x2::get(int row, int column) const
{
	return matrix[row][column];
}

void Matrix2x2::set(int row, int column, double value)
{
	matrix[row][column] = value;
}

Matrix2x2::Matrix2x2()
{
	set(0, 0, 1);
	set(1, 1, 1);
	set(0, 1, 0);
	set(1, 0, 0);
}

Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
	set(0, 0, a);
	set(0, 1, b);
	set(1, 0, c);
	set(1, 1, d);
}


void Matrix2x2::printMatrix()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrix[i][j];
		}
	}
}

double Matrix2x2::det() const
{
	return this->get(0, 0) * this->get(1, 1) + this->get(0, 1) * this->get(1, 0);
}

bool Matrix2x2::inverse(Matrix2x2 &matrix) const
{
	double det = matrix.det();
	if (det == 0)
		return false;
	else
	{
		Matrix2x2 invertMatrix(1 / det *matrix.get(1, 1), 1 / det *-matrix.get(0, 1), 1 / det *-matrix.get(1, 0), 1 / det *matrix.get(0, 0));
		matrix = invertMatrix;
		return true;
	}
}



//Operatører
ostream& operator << (ostream &out, const Matrix2x2 matrix)
{
	out << matrix.get(0, 0) << " " << matrix.get(0, 1) << endl << matrix.get(1, 0) << " " << matrix.get(1, 1) << endl;
	return out;
}

Matrix2x2& operator += (Matrix2x2 &m, Matrix2x2 a)
{
	m.set(0, 0, a.get(0, 0) + m.get(0, 0));
	m.set(0, 1, a.get(0, 1) + m.get(0, 1));
	m.set(1, 0, a.get(1, 0) + m.get(1, 0));
	m.set(1, 1, a.get(1, 1) + m.get(1, 1));
	return m;
}

Matrix2x2& operator -= (Matrix2x2 &m, Matrix2x2 a)
{
	m.set(0, 0, m.get(0, 0) - a.get(0, 0));
	m.set(0, 1, m.get(0, 1) - a.get(0, 1));
	m.set(1, 0, m.get(1, 0) - a.get(1, 0));
	m.set(1, 1, m.get(1, 1) - a.get(1, 1));
	return m;
}

Matrix2x2& operator + (Matrix2x2 &m, Matrix2x2 a)
{
	m += a;
	return m;
}

Matrix2x2& operator - (Matrix2x2 &m, Matrix2x2 a)
{
	m -= a;
	return m;
}

Matrix2x2& operator * (Matrix2x2 m, Matrix2x2 a)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			double value = 0;
			for (int k = 0; k < 2; k++)
			{
				value += m.get(i, k) * a.get(k, j);
			}
			m.set(i, j, value);
		}
	}
	return m;
}

Matrix2x2& operator *= (Matrix2x2 &matrix, Matrix2x2 factor)
{
	matrix = matrix * factor;
	return matrix;
}

Vector2& operator * (Matrix2x2 mat, Vector2 vec)
{
	Vector2 result;
	result.setX(mat.get(0, 0)*vec.getX() + mat.get(0, 1) * vec.getY());
	result.setY(mat.get(1, 0)*vec.getX() + mat.get(1, 1) * vec.getY());
	return result;
}