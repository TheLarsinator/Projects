#include "Image.h"
#include "stdafx.h"
/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( unsigned int width, unsigned int height ) : width(width), height(height)
{
	data = new Pixel[width * height];
}

Image::~Image()  {
	delete[] data;
	data = nullptr;
}

unsigned int Image::getWidth() const {
   /* Enter your code here */
   return width;
}
unsigned int Image::getHeight() const  {
   /* Enter your code here */ 
   return height;
}

const Pixel * Image::getScanLine(unsigned int line) const  {
	if (line < height)
		return &data[width * line];
}

Pixel * Image::getScanLine(unsigned int line) {
	if(line < height)
		return &data[width * line];
}

Color Image::getPixelColor( unsigned int x, unsigned int y ) const {
	if (x < width && y < height)
		return data[y * width + x];
}
void Image::setPixelColor( unsigned int x, unsigned int y, const Color &color ) {
	if (x <= width && y <= height)
		data[y*width + x] = color;
}

void Image::fill( const Color &color ) {
	for (int i = 0; i < height*width; i++)
	{
		data[i] = color;
	}
}