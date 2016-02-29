#pragma once
#include <iostream>

using namespace std;

class Vector2
{
private:
	double vector2[2];
public:
	double Vector2::getX() const;
	double Vector2::getY() const;
	void Vector2::setY(double val);
	void Vector2::setX(double val);
	double Vector2::dot(const Vector2 &rhs) const;
	double Vector2::lenghtSquared() const;
	double Vector2::length();
	Vector2::Vector2();
	Vector2::Vector2(double a, double b);
};

ostream& operator<<(ostream &out, Vector2 vector);
