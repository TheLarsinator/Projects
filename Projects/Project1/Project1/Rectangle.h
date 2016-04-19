#pragma once
#include "Image.h"
#include "Shape.h"
#include <iostream>
#include "Line.h"
using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(Coordinate start, Coordinate stop, Color &color) : nedre(start), ovre(stop), Shape(color) {}
	void draw(Image &bilde) const
	{
		//Har diagonalen. Skal tegne streker mellom dem. 
		Coordinate top;
		Coordinate bottom;
		
		top = Coordinate(nedre.x, ovre.y);
		bottom = Coordinate(ovre.x, nedre.y);

		Line a(nedre, bottom, Shape::getColor());
		Line b(bottom, ovre, Shape::getColor());
		Line c(top, ovre, Shape::getColor());
		Line d(nedre, top, Shape::getColor());

		cout << "TEGN!!!" << endl;
		a.draw(bilde);
		b.draw(bilde);
		c.draw(bilde);
		d.draw(bilde);
	}
private:
	Coordinate nedre;
	Coordinate ovre;

	//Disse regner vi ut i draw

};