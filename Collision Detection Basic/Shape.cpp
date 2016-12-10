#include "Shape.h"


Shape::Shape(float x, float y, float w, float h)
	:state_array{x,y,w,h}
{
}

Shape::~Shape()
{
}

float Shape::get_x_pos() const
{
	return state_array[0];
}

float Shape::get_y_pos() const
{
	return state_array[1];
}

float Shape::get_height() const
{
	return state_array[2];
}

float Shape::get_width() const
{
	return state_array[3];
}

void Shape::move_on_x_to(float num)
{
	Shape::state_array[0] = num;
}

void Shape::move_on_y_to(float num)
{
	Shape::state_array[1] = num;
}

void Shape::move_on_x_and_y_to(float x, float y)
{
	Shape::move_on_x_to(x);
	Shape::move_on_y_to(y);
}

bool Shape::is_overlaping_with(const Shape& shape) const
{
	throw UnsuportedShapeException();
}

string Shape::to_string() const {
	throw UnsuportedShapeException();
}