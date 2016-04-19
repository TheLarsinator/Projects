#pragma once

#include <vector>
#include <iostream>
#include "Shape.h"
#include "Image.h"
using namespace std;

class Canvas
{
private:
	vector<Shape*> shapes;

public:
	Canvas();
	void addShape(Shape *figur);
	void rasterizeTo(Image &bilde);
};