#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Circle : public Shape
{
public:
	Circle(float x, float y, float r);
	virtual ~Circle();
	float getRadious() const;

	bool is_overlaping_with(Shape circleOrSquare) override;

};
