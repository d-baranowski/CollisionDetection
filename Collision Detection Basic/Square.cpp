#include "Square.h"
#include "Circle.h"
#include "MyConstants.h"

using namespace std;

Square::Square() : Shape(), state_array{ MIN_OBJECT_SIDE_LENGTH, MIN_OBJECT_SIDE_LENGTH, MIN_OBJECT_SIDE_LENGTH }
{} 


Square::~Square()
{}

Square::Square(float x, float y, float w) : Shape(), state_array{x,y,w}
{}

float Square::get_x_pos() const
{
	return state_array[X_INDEX];
}

float Square::get_y_pos() const
{
	return state_array[Y_INDEX];
}

float Square::get_width() const
{
	return get_side_length();
}

float Square::get_height() const
{
	return get_side_length();
}

float Square::get_side_length() const
{
	return state_array[W_INDEX];
}

//I could remove less or equals and use less but that wouldn't be able to tell if object with same dimensions and possition are overlaping
bool Square::is_overlaping_with(const Shape& rectangleOrCircle) const
{
	if (const Circle* circle = dynamic_cast<const Circle*> (&rectangleOrCircle))
	{
		return circle->is_overlaping_with(this);
	}
	else if (const Square* square = dynamic_cast<const Square*> (&rectangleOrCircle)) {
		return is_overlaping_with(square);
	}

	throw UnsuportedShapeException();
}

bool Square::is_overlaping_with(const Square* square) const
{
	return
		this->get_x_pos() < square->get_x_pos() + square->get_side_length() &&
		this->get_x_pos() + this->get_width() > square->get_x_pos() &&
		this->get_y_pos() < square->get_y_pos() + square->get_height() &&
		this->get_y_pos() + this->get_height() > square->get_y_pos();
}

string Square::to_string() const {
	return "Square[x:" + std::to_string(get_x_pos())
		+ " y:" + std::to_string(get_y_pos())
		+ " w:" + std::to_string(get_width())
		+ "]";
}

void Square::move_on_x_to(float newX)
{
	state_array[X_INDEX] = newX;
}

void Square::move_on_y_to(float newY)
{
	state_array[Y_INDEX] = newY;
}
