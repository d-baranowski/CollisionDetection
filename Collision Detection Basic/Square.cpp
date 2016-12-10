#include "Square.h"
#include "Circle.h"
#include <algorithm>

using namespace std;

Square::Square() : Shape(0,0,0,0)
{}

Square::~Square()
{}

Square::Square(int x, int y, int w, int h) : Shape(x, y, w, h)
{}

//I could remove less or equals and use less but that wouldn't be able to tell if object with same dimensions and possition are overlaping
bool Square::is_overlaping_with(const Shape& rectangleOrCircle) const
{
	if (const Circle* circle = dynamic_cast<const Circle*> (&rectangleOrCircle))
	{
		const float deltaX = circle->get_x_pos() - max(this->get_x_pos(), min(circle->get_x_pos(), this->get_x_pos() + this->get_width()));
		const float deltaY = circle->get_y_pos() - max(this->get_y_pos(), min(circle->get_y_pos(), this->get_y_pos() + this->get_height()));
		return (deltaX * deltaX + deltaY * deltaY) < ((*circle).get_radious() * (*circle).get_radious());
	}
	else if (const Square* rectangle = dynamic_cast<const Square*> (&rectangleOrCircle)) {
		return
			this->get_x_pos() <= rectangle->get_x_pos() + rectangle->get_width() &&
			this->get_x_pos() + this->get_width() >= rectangle->get_x_pos() &&
			this->get_y_pos() <= rectangle->get_y_pos() + rectangle->get_height() &&
			this->get_y_pos() + this->get_height() >= rectangle->get_y_pos();
	}

	throw UnsuportedShapeException();
}

string Square::to_string() const {
	return "Square[x:" + std::to_string(get_x_pos())
		+ " y:" + std::to_string(get_y_pos())
		+ " w:" + std::to_string(get_width())
		+ "]";
}
