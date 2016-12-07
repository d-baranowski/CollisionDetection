#include "Shape.h"

Shape::Shape(int x, int y, int w, int h)
{
	state[0] = x;
	state[1] = y;
	state[2] = h;
	state[3] = w;
}

Shape::~Shape()
{
}

int Shape::getXPos() const
{
	return state[0];
}

int Shape::getYPos() const
{
	return state[1];
}

int Shape::getHeight() const
{
	return state[2];
}

int Shape::getWidth() const
{
	return state[3];
}

void Shape::moveOnXTo(int num)
{
	Shape::state[0] = num;
}

void Shape::moveOnYTo(int num)
{
	Shape::state[1] = num;
}

void Shape::moveOnXandY(int x, int y)
{
	Shape::moveOnXTo(x);
	Shape::moveOnYTo(y);
}

bool Shape::isOverlapingWith(Shape shape)
{
	return false;
}
