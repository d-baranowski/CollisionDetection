#include "Shape.h"


Shape::Shape() : has_collided(false), collided_with("")
{}

Shape::~Shape()
{}

float Shape::get_x_pos() const
{
	throw UnsuportedShapeException();
}

float Shape::get_y_pos() const
{
	throw UnsuportedShapeException();
}

float Shape::get_height() const
{
	throw UnsuportedShapeException();
}

float Shape::get_width() const
{
	throw UnsuportedShapeException();
}

void Shape::move_on_x_to(float newX)
{
	throw UnsuportedShapeException();
}

void Shape::move_on_y_to(float newY)
{
	throw UnsuportedShapeException();
}

void Shape::move_on_x_and_y_to(float x, float y)
{
	move_on_x_to(x);
	move_on_y_to(y);
}

bool Shape::is_overlaping_with(const Shape& shape) const
{
	throw UnsuportedShapeException();
}

string Shape::to_string() const {
	throw UnsuportedShapeException();
}