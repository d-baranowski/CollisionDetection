#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, int r);
	int getRadious() const;

	bool isOverlapingWith(Shape circleOrSquare) override;

};
