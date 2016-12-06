#include "Shape.h"
#include "Rectangle.h"
#include "Assertions.h"

#include <iostream>
#include "Circle.h"
using namespace std;

int test()
{
	Assertions::assertTrue(Rectangle(170, 139, 177, 130)
		.isOverlapingWith(Rectangle(106, 83, 101, 102)),
			"These squares should overlap");
	Assertions::assertTrue(!Rectangle(178, 98, 96, 90)
		.isOverlapingWith(Rectangle(380, 81, 101, 102)),
			"These squares should not overlap");
	Assertions::assertTrue(Circle(171,309,43)
		.isColidingWith(Circle(128,301,36)),
			"These circles should overlap");
	Assertions::assertTrue(!Circle(171, 309, 43)
		.isColidingWith(Circle(263, 279, 36))
		, "These circles should not overlap");
	Assertions::assertTrue(areColliding(Circle(166, 204, 36), Rectangle(178, 98, 96, 90)),
		"This circle should overlap with this rectangle");
	Assertions::assertTrue(!areColliding(Circle(145, 78, 36), Rectangle(178, 98, 96, 90)),
		"This circle should not overlap with this rectangle");

	cout << Assertions::getErrors();
	return Assertions::getCode();
}

int main()
{
	test();
	Rectangle one = Rectangle(11, 11 , 2, 2);
	Rectangle two = Rectangle(10, 10, 2000, 2000);
	cout << one.isOverlapingWith(two) << "\n";

	system("PAUSE");
}
