#pragma once
#include <exception>
#include <iostream>   
#include <string> 

using namespace std;

struct UnsuportedShapeException : public std::exception {
	const char * what() const throw () override {
		return "You're using a shape that is not supported by this program.";
	}
};

class Shape
{
public:
	Shape(float x, float y, float w, float h);
	virtual ~Shape();
	float get_x_pos()  const;
	float get_y_pos()  const;
	
	virtual float get_height() const;
	virtual float get_width() const;
	virtual bool is_overlaping_with(const Shape& shape) const;
	virtual string to_string() const;
	
	void move_on_x_to(float num);
	void move_on_y_to(float num);
	void move_on_x_and_y_to(float x, float y);

	bool has_collided = false;
	string collided_with = "";

	
protected:
	float state_array[4];
};



