#include <cmath>     
#include <algorithm>

#include "Shape.h"
#include "Circle.h"
#include <iostream>


using namespace std;


Circle::Circle(float x, float y, float r) : Shape(x, y, r * 2, r * 2)
{}

float Circle::getRadious() const
{
	return get_width() / 2;
}

Circle::~Circle()
{
	
}

bool Circle::is_overlaping_with(Shape circleOrRectangle)
{
	if (Circle* circle = dynamic_cast<Circle*> (&circleOrRectangle))
	{
		return abs((this->get_x_pos() - (*circle).get_x_pos()) * (this->get_x_pos() - (*circle).get_x_pos())
			+ (this->get_y_pos() - (*circle).get_y_pos()) * (this->get_y_pos() - (*circle).get_y_pos()))
			< (this->getRadious() + (*circle).getRadious()) * (this->getRadious() + (*circle).getRadious());
	}

	const int deltaX = this->get_x_pos() - max(circleOrRectangle.get_x_pos(), min(this->get_x_pos(), circleOrRectangle.get_x_pos() + circleOrRectangle.get_width()));
	const int deltaY = this->get_y_pos() - max(circleOrRectangle.get_y_pos(), min(this->get_y_pos(), circleOrRectangle.get_y_pos() + circleOrRectangle.get_height()));
	return (deltaX * deltaX + deltaY * deltaY) < (this->getRadious() * this->getRadious());
}
