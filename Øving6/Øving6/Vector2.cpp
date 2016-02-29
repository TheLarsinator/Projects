#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <string>
#include "Vector2.h"

using namespace std;

double Vector2::getX() const
{
	return vector2[0];
}

double Vector2::getY() const
{
	return vector2[1];
}

void Vector2::setX(double val)
{
	vector2[0] = val;
}

void Vector2::setY(double val)
{
	vector2[1] = val;
}

double Vector2::dot(const Vector2 &rhs) const
{
	return (this->getX() * rhs.getX() + this->getY() * rhs.getY());
}

double Vector2::lenghtSquared() const
{
	return this->dot(*this);
}

double Vector2::length()
{
	return sqrt(this->lenghtSquared());
}

Vector2::Vector2()
{
	this->setX(0);
	this->setY(0);
}

Vector2::Vector2(double a, double b)
{
	this->setX(a);
	this->setY(b);
}




ostream& operator << (ostream &out, const Vector2 vector)
{
	out << vector.getX() << " " << vector.getY() << endl;
	return out;
}

