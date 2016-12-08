#pragma once
class Shape
{
public:
	Shape(float x, float y, float w, float h);
	virtual ~Shape();
	float get_x_pos()  const;
	float get_y_pos()  const;
	float get_height() const;
	float get_width() const;
	
	void move_on_x_to(float num);
	void move_on_y_to(float num);
	void move_on_x_and_y_to(float x, float y);

	bool has_collided_ = false;
	virtual bool is_overlaping_with(Shape shape);
protected:
	int state[4];
};

