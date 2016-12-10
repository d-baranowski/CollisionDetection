#pragma once
#include "Shape.h"

class Square : public Shape 
{
public:
	Square();
	virtual ~Square();
	Square(float x, float y, float w);

	float get_x_pos()  const override;
	float get_y_pos()  const override;

	float get_height() const override;
	float get_width() const override;
	float get_side_length() const;
	bool is_overlaping_with(const Shape& squareOrCircle) const override;

	bool is_overlaping_with(const Square* square) const;
	string to_string() const override;

	void move_on_x_to(float newX) override;
	void move_on_y_to(float newY) override;
private:
	float state_array[3];
	const int
		X_INDEX = 0,
		Y_INDEX = 1,
		W_INDEX = 2;
};