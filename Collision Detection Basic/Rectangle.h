#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, int w, int h);
	int getWidth() const;
	int getHeight() const;
	bool isOverlapingWith(Rectangle rectangle)  const;

private:
	int dimensions[2];
};

