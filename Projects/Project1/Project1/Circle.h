#pragma once
#include "Image.h"
#include "Shape.h"
#include <iostream>
#include "Line.h"
#include <cmath>

using namespace std;
double PI = 3.141592654;

bool compareColors(const Color &a, const Color &b)
{
	return (a.blue == b.blue && a.red == b.red && a.green == b.green);
}

// Coordinate struct
struct Interval {
	Interval(unsigned int x, unsigned int y) : x(x), y(y) {
		/*Empty*/
	}
	Interval() : x(0), y(0) {
		/*Empty*/
	}
	unsigned int x, y;
};

class Circle : public Shape
{
public:
	Circle(Coordinate sentrum, unsigned int radius, Interval angle, Color &color) : sentrum(sentrum), radius(radius), angle(angle), angles(0), Shape(color) {}
	Circle(Coordinate sentrum, unsigned int radius, double angles, Color &color) : sentrum(sentrum), radius(radius), angles(angles), angle(Interval(0, 0)), Shape(color) {}

	void draw(Image &bilde)const
	{
		cout << "tegner" << endl;
		if (angles == 0)
		{
			for (double i = angle.x; i < angle.y; i += 0.01)
			{
				if(compareColors(bilde.getPixelColor(radius*cos(i) + sentrum.x, radius*sin(i) + sentrum.y), this->getColor()))
					bilde.setPixelColor(radius*cos(i) + sentrum.x, radius*sin(i) + sentrum.y, this->getColor());
			}
		}
		else
		{
			if (angles < 0)
			{
				for (double i = angles; i < 0; i += 0.01)
				{
					bilde.setPixelColor(radius*cos(i) + sentrum.x, radius*sin(i) + sentrum.y, this->getColor());
				}
			}
			else
			{
				for (double i = PI - angles; i < PI; i += 0.01)
				{
					bilde.setPixelColor(radius*cos(i) + sentrum.x, radius*sin(i) + sentrum.y, this->getColor());
				}
				cout << "Angles != 0" << endl;
			}
		}
	}
private:
	Coordinate sentrum;
	unsigned int radius;
	Interval angle;
	double angles;
};

