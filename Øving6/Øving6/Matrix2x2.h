#pragma once
#include <iostream>
#include "Vector2.h"
using namespace std;
class Matrix2x2
{
private: 
	double matrix[2][2];
public:
	void Matrix2x2::printMatrix();
	double Matrix2x2::get(int row, int column) const;
	void Matrix2x2::set(int row, int column, double variable);
	Matrix2x2::Matrix2x2();
	Matrix2x2::Matrix2x2(double, double, double, double);
	double Matrix2x2::det() const;
	bool Matrix2x2::inverse(Matrix2x2 &matrix) const;

};

ostream& operator<<(ostream &out, Matrix2x2 matrix);
Matrix2x2& operator += (Matrix2x2 &m, Matrix2x2 a);
Matrix2x2& operator -= (Matrix2x2 &m, Matrix2x2 a);
Matrix2x2& operator + (Matrix2x2 &m, Matrix2x2 a);
Matrix2x2& operator - (Matrix2x2 &m, Matrix2x2 a);
Matrix2x2& operator * (Matrix2x2 m, Matrix2x2 a);
Matrix2x2& operator *= (Matrix2x2 &matrix, Matrix2x2 factor);
Vector2& operator * (Matrix2x2 mat, Vector2 vec);