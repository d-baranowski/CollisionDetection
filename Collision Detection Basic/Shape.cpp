#include "Shape.h"

Shape::Shape(float x, float y, float w, float h)
{
	state[0] = x;
	state[1] = y;
	state[2] = h;
	state[3] = w;
}

Shape::~Shape()
{
}

float Shape::get_x_pos() const
{
	return state[0];
}

float Shape::get_y_pos() const
{
	return state[1];
}

float Shape::get_height() const
{
	return state[2];
}

float Shape::get_width() const
{
	return state[3];
}

void Shape::move_on_x_to(float num)
{
	Shape::state[0] = num;
}

void Shape::move_on_y_to(float num)
{
	Shape::state[1] = num;
}

void Shape::move_on_x_and_y_to(float x, float y)
{
	Shape::move_on_x_to(x);
	Shape::move_on_y_to(y);
}

bool Shape::is_overlaping_with(Shape shape)
{
	return false;
}
