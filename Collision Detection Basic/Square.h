#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square();
	virtual ~Square();
	Square(int x, int y, int w, int h);
	bool is_overlaping_with(const Shape& square) const override;
	string to_string() const override;
};