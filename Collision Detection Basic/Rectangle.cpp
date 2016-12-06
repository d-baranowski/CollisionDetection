#include "Rectangle.h"

Rectangle::Rectangle() : Shape(0,0,0,0)
{}

Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y,w,h)
{}


//I could remove less or equals and use less but that wouldn't be able to tell if object with same dimensions and possition are overlaping
bool Rectangle::isOverlapingWith(Rectangle rectangle)  const
{
	return 
		this->getXPos() <= rectangle.getXPos() + rectangle.getWidth() &&
		this->getXPos() + this->getWidth() >= rectangle.getXPos() &&
		this->getYPos() <= rectangle.getYPos() + rectangle.getHeight() &&
		this->getYPos() + this->getHeight() >= rectangle.getYPos();
}

