#include <cmath>     
#include <algorithm>

#include "Shape.h"
#include "Circle.h"


using namespace std;


Circle::Circle(float x, float y, float r) : Shape(), state_array{x,y,r}
{}

float Circle::get_x_pos() const
{
	return state_array[X_INDEX];
}

float Circle::get_y_pos() const
{
	return state_array[Y_INDEX];
}

float Circle::get_radious() const
{
	return state_array[R_INDEX];
}

float Circle::get_width() const
{
	return get_radious() * 2;
}

float Circle::get_height() const
{
	return get_radious() * 2;
}

Circle::~Circle()
{
	
}

bool Circle::is_overlaping_with(const Shape& circleOrRectangle) const
{
	if (const Circle* circle = dynamic_cast<const Circle*> (&circleOrRectangle))
	{
		return abs((this->get_x_pos() - circle->get_x_pos()) * (this->get_x_pos() - circle->get_x_pos())
			+ (this->get_y_pos() - circle->get_y_pos()) * (this->get_y_pos() - circle->get_y_pos()))
			< (this->get_radious() + circle->get_radious()) * (this->get_radious() + circle->get_radious());
	}
	else if (const Square* square = dynamic_cast<const Square*> (&circleOrRectangle)) {
		return is_overlaping_with(square);
	}
	
	throw UnsuportedShapeException();
}

bool Circle::is_overlaping_with(const Square* square) const
{
	const float deltaX = this->get_x_pos() - max(square->get_x_pos(), min(this->get_x_pos(), square->get_x_pos() + square->get_side_length()));
	const float deltaY = this->get_y_pos() - max(square->get_y_pos(), min(this->get_y_pos(), square->get_y_pos() + square->get_side_length()));
	return (deltaX * deltaX + deltaY * deltaY) < (this->get_radious() * this->get_radious());
}

string Circle::to_string() const {
	return "Circle[x:" + std::to_string(get_x_pos())
		+ " y:" + std::to_string(get_y_pos())
		+ " r:" + std::to_string(get_radious())
		+ "]";
}

void Circle::move_on_x_to(float newX)
{
	state_array[X_INDEX] = newX;
}

void Circle::move_on_y_to(float newY)
{
	state_array[Y_INDEX] = newY;
}
