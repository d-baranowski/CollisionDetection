#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle();
	virtual ~Rectangle();
	Rectangle(int x, int y, int w, int h);
	bool is_overlaping_with(Shape rectangle) override;
};

