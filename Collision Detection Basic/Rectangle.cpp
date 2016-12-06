#include "Rectangle.h"



Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y)
{
	this->dimensions[0] = w;
	this->dimensions[1] = h;
}

int Rectangle::getWidth()  const
{
	return dimensions[0];
}

int Rectangle::getHeight()  const
{
	return dimensions[1];
}

//I could remove less or equals and use less but that wouldn't be able to tell if object with same dimensions and possition are overlaping
bool Rectangle::isOverlapingWith(Rectangle rectangle)  const
{
	return 
		this->getXPos() <= rectangle.getXPos() + rectangle.getWidth() &&
		this->getXPos() + this->getWidth() >= rectangle.getXPos() &&
		this->getYPos() <= rectangle.getYPos() + rectangle.getHeight() &&
		this->getYPos() + this->getHeight() >= rectangle.getYPos();
}

