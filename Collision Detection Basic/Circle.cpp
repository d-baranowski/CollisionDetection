#include "Circle.h"

#include <cmath>     
#include <algorithm>
using namespace std;


Circle::Circle(int x, int y, int r) : Shape(x,y, r * 2, r * 2)
{
	this->r = r;
}

int Circle::getRadious() const
{
	return r;
}

bool Circle::isColidingWith(Circle circle) const
{
	return abs((this->getXPos() - circle.getXPos()) * (this->getXPos() - circle.getXPos()) 
		+ (this->getYPos() - circle.getYPos()) * (this->getYPos() - circle.getYPos()))
		< (this->getRadious() + circle.getRadious()) * (this->getRadious() + circle.getRadious());
}

bool areColliding(Circle circle, Rectangle rectangle)
{
	int deltaX = circle.getXPos() - max(rectangle.getXPos(), min(circle.getXPos(), rectangle.getXPos() + rectangle.getWidth()));
	int deltaY = circle.getYPos() - max(rectangle.getYPos(), min(circle.getYPos(), rectangle.getYPos() + rectangle.getHeight()));
	return (deltaX * deltaX + deltaY * deltaY) < (circle.getRadious() * circle.getRadious());
}
