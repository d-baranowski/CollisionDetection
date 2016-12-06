#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, int r);
	int getRadious() const;

	bool isColidingWith(Circle circle) const;

private:
	int r;
};

bool areColliding(Circle circle, Rectangle rectangle);

