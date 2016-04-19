#include "Vector.h"
#include "Matrix.h"
#include <cmath>
#include "stdafx.h"

Vector::Vector() : Matrix()
{

}

Vector::Vector(unsigned int nuRows) : Matrix(nuRows, 1, 1)
{
	
}

Vector::Vector(const Matrix &other) : Matrix()
{
	if (other.getColumns() == 1)
	{
		*this = Matrix::operator =(other);
	}
}

void Vector::set(int row, double value)
{
	Matrix::set(row, 1, value);
}

double Vector::get(int row) const
{
	return Matrix::get(row, 1);
}

double Vector::dot(const Vector &rhs) const
{
	int sum = 0;
	if (rhs.getRows() == this->getRows())
	{
		for (int i = 0; i < rhs.getRows(); i++)
		{
			sum += rhs.get(i) + this->get(i);
		}
		return sum;
	}
	else
		return nan("");
}

double Vector::lengthSquared() const
{
	return this->dot(*this);
}

double Vector::length() const
{
	return sqrt(lengthSquared());
}