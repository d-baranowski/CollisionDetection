#pragma once
#include "Shape.h"
#include "Square.h"

class Circle : public Shape
{
public:
	Circle(float x, float y, float r);
	virtual ~Circle();
	float get_radious() const;

	bool is_overlaping_with(const Shape& circleOrSquare) const override;
	string to_string() const override;
};
