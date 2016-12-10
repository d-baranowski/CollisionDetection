#include <cmath>     
#include <algorithm>

#include "Shape.h"
#include "Circle.h"


using namespace std;


Circle::Circle(float x, float y, float r) : Shape(x, y, r * 2, r * 2)
{}

float Circle::get_radious() const
{
	return get_width() / 2;
}

Circle::~Circle()
{
	
}

bool Circle::is_overlaping_with(const Shape& circleOrRectangle) const
{
	if (const Circle* circle = dynamic_cast<const Circle*> (&circleOrRectangle))
	{
		return abs((this->get_x_pos() - circle->get_x_pos()) * (this->get_x_pos() - circle->get_x_pos())
			+ (this->get_y_pos() - circle->get_y_pos()) * (this->get_y_pos() - circle->get_y_pos()))
			< (this->get_radious() + circle->get_radious()) * (this->get_radious() + circle->get_radious());
	}
	else if (const Square* rectangle = dynamic_cast<const Square*> (&circleOrRectangle)) {
		const float deltaX = this->get_x_pos() - max(rectangle->get_x_pos(), min(this->get_x_pos(), rectangle->get_x_pos() + rectangle->get_width()));
		const float deltaY = this->get_y_pos() - max(rectangle->get_y_pos(), min(this->get_y_pos(), rectangle->get_y_pos() + rectangle->get_height()));
		return (deltaX * deltaX + deltaY * deltaY) < (this->get_radious() * this->get_radious());
	}
	
	throw UnsuportedShapeException();
}

string Circle::to_string() const {
	return "Circle[x:" + std::to_string(get_x_pos())
		+ " y:" + std::to_string(get_y_pos())
		+ " r:" + std::to_string(get_radious())
		+ "]";
}
