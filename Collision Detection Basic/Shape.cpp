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

float Shape::getXPos() const
{
	return state[0];
}

float Shape::getYPos() const
{
	return state[1];
}

float Shape::getHeight() const
{
	return state[2];
}

float Shape::getWidth() const
{
	return state[3];
}

void Shape::moveOnXTo(float num)
{
	Shape::state[0] = num;
}

void Shape::moveOnYTo(float num)
{
	Shape::state[1] = num;
}

void Shape::moveOnXandY(float x, float y)
{
	Shape::moveOnXTo(x);
	Shape::moveOnYTo(y);
}

bool Shape::isOverlapingWith(Shape shape)
{
	return false;
}
