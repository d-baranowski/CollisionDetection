#include "Shape.h"

Shape::Shape(int x, int y, int w, int h)
{
	state[0] = x;
	state[1] = y;
	state[2] = h;
	state[3] = w;
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
