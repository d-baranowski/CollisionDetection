#include <cmath>     
#include <algorithm>

#include "Shape.h"
#include "Circle.h"
#include <iostream>


using namespace std;


Circle::Circle(int x, int y, int r) : Shape(x, y, r * 2, r * 2)
{}

int Circle::getRadious() const
{
	return getWidth() / 2;
}

Circle::~Circle()
{
	
}

bool Circle::isOverlapingWith(Shape circleOrRectangle)
{
	if (Circle* circle = dynamic_cast<Circle*> (&circleOrRectangle))
	{
		return abs((this->getXPos() - (*circle).getXPos()) * (this->getXPos() - (*circle).getXPos())
			+ (this->getYPos() - (*circle).getYPos()) * (this->getYPos() - (*circle).getYPos()))
			< (this->getRadious() + (*circle).getRadious()) * (this->getRadious() + (*circle).getRadious());
	}

	const int deltaX = this->getXPos() - max(circleOrRectangle.getXPos(), min(this->getXPos(), circleOrRectangle.getXPos() + circleOrRectangle.getWidth()));
	const int deltaY = this->getYPos() - max(circleOrRectangle.getYPos(), min(this->getYPos(), circleOrRectangle.getYPos() + circleOrRectangle.getHeight()));
	return (deltaX * deltaX + deltaY * deltaY) < (this->getRadious() * this->getRadious());
}
