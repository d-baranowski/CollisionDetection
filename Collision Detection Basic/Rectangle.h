#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(int x, int y, int w, int h);
	bool isOverlapingWith(Shape rectangle) override;
};

