#pragma once

#include "Image.h"

// Coordinate struct
struct Coordinate {
	Coordinate(unsigned int x, unsigned int y) : x(x), y(y){
		/*Empty*/
	}
	Coordinate() : x(0), y(0){
		/*Empty*/
	}
	unsigned int x, y;
};

class Shape
{
private:
	Color farge;
public:
	Shape() {};
	Shape(Color &color) : farge(color) {}
	void setColor(Color &color) { farge = color; }
	Color getColor()const { return farge; }
	virtual void draw(Image &bilde)const = 0;
};