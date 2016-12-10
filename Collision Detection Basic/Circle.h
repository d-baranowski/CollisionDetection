#pragma once
#include "Shape.h"
#include "Square.h"

class Circle : public Shape
{
public:
	Circle(float x, float y, float r);
	virtual ~Circle();
	float get_radious() const;
	float get_x_pos()  const override;
	float get_y_pos()  const override;
	float get_height() const override;
	float get_width() const override;


	bool is_overlaping_with(const Shape& circleOrSquare) const override;
	bool is_overlaping_with(const Square* square) const;
	string to_string() const override;

	void move_on_x_to(float newX) override;
	void move_on_y_to(float newY) override;

private:
	float state_array[3];
	const int 
		X_INDEX = 0,
		Y_INDEX = 1,
		R_INDEX = 2;
};
