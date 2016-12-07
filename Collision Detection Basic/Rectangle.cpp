#include "Rectangle.h"
#include "Circle.h"
#include <algorithm>

using namespace std;

Rectangle::Rectangle() : Shape(0,0,0,0)
{}

Rectangle::~Rectangle()
{
	
}

Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y, w, h)
{}

//I could remove less or equals and use less but that wouldn't be able to tell if object with same dimensions and possition are overlaping
bool Rectangle::isOverlapingWith(Shape rectangleOrCircle)
{
	if (Circle* circle = dynamic_cast<Circle*> (&rectangleOrCircle))
	{
		const int deltaX = (*circle).getXPos() - max(this->getXPos(), min((*circle).getXPos(), this->getXPos() + this->getWidth()));
		const int deltaY = (*circle).getYPos() - max(this->getYPos(), min((*circle).getYPos(), this->getYPos() + this->getHeight()));
		return (deltaX * deltaX + deltaY * deltaY) < ((*circle).getRadious() * (*circle).getRadious());
	}

	return 
		this->getXPos() <= rectangleOrCircle.getXPos() + rectangleOrCircle.getWidth() &&
		this->getXPos() + this->getWidth() >= rectangleOrCircle.getXPos() &&
		this->getYPos() <= rectangleOrCircle.getYPos() + rectangleOrCircle.getHeight() &&
		this->getYPos() + this->getHeight() >= rectangleOrCircle.getYPos();
}

