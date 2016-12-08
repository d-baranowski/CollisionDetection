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
bool Rectangle::is_overlaping_with(Shape rectangleOrCircle)
{
	if (Circle* circle = dynamic_cast<Circle*> (&rectangleOrCircle))
	{
		const int deltaX = (*circle).get_x_pos() - max(this->get_x_pos(), min((*circle).get_x_pos(), this->get_x_pos() + this->get_width()));
		const int deltaY = (*circle).get_y_pos() - max(this->get_y_pos(), min((*circle).get_y_pos(), this->get_y_pos() + this->get_height()));
		return (deltaX * deltaX + deltaY * deltaY) < ((*circle).getRadious() * (*circle).getRadious());
	}

	return 
		this->get_x_pos() <= rectangleOrCircle.get_x_pos() + rectangleOrCircle.get_width() &&
		this->get_x_pos() + this->get_width() >= rectangleOrCircle.get_x_pos() &&
		this->get_y_pos() <= rectangleOrCircle.get_y_pos() + rectangleOrCircle.get_height() &&
		this->get_y_pos() + this->get_height() >= rectangleOrCircle.get_y_pos();
}

