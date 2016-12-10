#pragma once
#include "Shape.h"

class Square : public Shape 
{
public:
	Square();
	virtual ~Square();
	Square(float x, float y, float w, float h);
	bool is_overlaping_with(const Shape& square) const override;
	string to_string() const override;
};