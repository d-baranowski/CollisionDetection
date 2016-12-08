#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, int r);
	virtual ~Circle();
	int getRadious() const;

	bool is_overlaping_with(Shape circleOrSquare) override;

};
