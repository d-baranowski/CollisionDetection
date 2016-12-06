#include "Shape.h"

Shape::Shape(int x, int y)
{
	this->state[0] = x;
	this->state[1] = y;
}

int Shape::getXPos() const
{
	return Shape::state[0];
}

int Shape::getYPos() const
{
	return Shape::state[1];
}

void Shape::moveOnXBy(int num)
{
	Shape::state[0] = state[0] + num;
}

void Shape::moveOnYBy(int num)
{
	Shape::state[1] = state[1] + num;
}

void Shape::moveOnXandY(int x, int y)
{
	Shape::moveOnXBy(x);
	Shape::moveOnYBy(y);
}
