#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, int r);
	virtual ~Circle();
	int getRadious() const;

	bool isOverlapingWith(Shape circleOrSquare) override;

};
