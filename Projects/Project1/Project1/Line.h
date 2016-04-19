#pragma once
#include "Image.h"
#include "Shape.h"
#include <iostream>

using namespace std;

class Line : public Shape
{
public:
	Line(Coordinate start, Coordinate stop, Color &color) : start(start), stop(stop), Shape(color) {}
	void draw(Image &bilde)const
	{
		cout << "tegner" << endl;

		double climb;
		if (start.x == stop.x)
			for (int i = start.y; i <= stop.y; i++)
			{
				bilde.setPixelColor(start.x, i, this->getColor());
			}
		else
		{
			double a = stop.y - start.y;
			double b = stop.x - start.x;
			climb = a / b;

			if (climb < 1)
			{
				for (int i = start.x; i <= stop.x; i++)
				{
					bilde.setPixelColor(i, (climb)*(i - start.x) + start.y, Shape::getColor());
				}
			}
			else
			{
				cout << "Drawing with Y" << endl;
				//Tegner langs Y-aksen for å få en fulstendig linje.
				for (int j = start.y; j <= stop.y; j++)
				{
					bilde.setPixelColor((unsigned int)((1 / climb)*(j - start.y) + start.x), j, Shape::getColor());
				}
			}
		}
	}
private:
	Coordinate start;
	Coordinate stop;
};