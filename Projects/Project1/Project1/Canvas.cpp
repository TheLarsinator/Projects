#include "Canvas.h"

Canvas::Canvas()
{
	
}

void Canvas::addShape(Shape * figur)
{
	shapes.push_back(figur);
}

void Canvas::rasterizeTo(Image &bilde)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw(bilde);
		cout << "Added shape number: " << i << endl;
	}
}