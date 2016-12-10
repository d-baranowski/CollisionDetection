#include "Assertions.h"
#include "Square.h"
#include "Circle.h"
#include <iostream>
#include "Quadtree.h"

void tests()
{
	//Rectangle
	Assertions::assert_true(Square(170, 139, 177, 130)
		.is_overlaping_with(Square(106, 83, 101, 102)),
		"These squares should overlap");
	Assertions::assert_true(!Square(178, 98, 96, 90)
		.is_overlaping_with(Square(380, 81, 101, 102)),
		"These squares should not overlap");
	//Circle
	Assertions::assert_true(Circle(171, 309, 43)
		.is_overlaping_with(Circle(128, 301, 36)),
		"These circles should overlap");
	Assertions::assert_true(!Circle(171, 309, 43)
		.is_overlaping_with(Circle(263, 279, 36))
		, "These circles should not overlap");

	//Circle / Rectangle
	Assertions::assert_true(Circle(166, 204, 36).is_overlaping_with(Square(178, 98, 96, 90)),
		"This circle should overlap with this rectangle");
	Assertions::assert_true(!(Circle(145, 78, 36).is_overlaping_with(Square(178, 98, 96, 90))),
		"This circle should not overlap with this rectangle");

	//Quadtree
	Quadtree& quadtree = *new Quadtree(0, Square(0, 0, 200, 200));
	Shape * circle_one = new Circle(49, 49, 8);
	Shape * square_zero = new Square(143, 38, 20, 20);
	Shape * square_two = new Square(40, 136, 20, 20);
	Shape * circle_three = new Circle(155, 150, 9);

	//Can insert into quadtree
	quadtree.insert(circle_one);
	quadtree.insert(square_zero);
	quadtree.insert(square_two);
	quadtree.insert(circle_three);

	vector<Shape*>& returnObjects = *new vector<Shape*>;

	quadtree.get_near_shapes(returnObjects, circle_one);

	Assertions::assert_true(
		find(returnObjects.begin(),
			returnObjects.end(),
			square_zero) != returnObjects.end(), "Should contain square zero.");

	Assertions::assert_true(
		find(returnObjects.begin(),
			returnObjects.end(),
			square_two) != returnObjects.end(), "Should contain square two.");

	Assertions::assert_true(
		find(returnObjects.begin(),
			returnObjects.end(),
			circle_three) != returnObjects.end(), "Should contain circle three.");

	//Add more objects so the quadtree splits
	Shape * node_two_objects[5] = {
		new Circle(12, 119, 6),
		new Circle(37, 113, 6),
		new Circle(77, 121, 6),
		new Circle(16, 141, 6),
		new Circle(64, 179, 6)
	};

	Shape * node_three_objects[2] = {
		new Square(119,116,20,20),
		new Square(165,108,20,20)
	};

	for (int i = 0; i<5; i++)
	{
		quadtree.insert(node_two_objects[i]);
		if (i < 2)
		{
			quadtree.insert(node_three_objects[i]);
		}
	}

	//See if I can get_near_shapes collision objects from node 0
	returnObjects.clear();
	quadtree.get_near_shapes(returnObjects, square_zero);

	Assertions::assert_true(returnObjects.size() == 0, "There should be no objects that can collide with square zero.");

	//See if I can get_near_shapes collision objects from node 1
	returnObjects.clear();
	quadtree.get_near_shapes(returnObjects, circle_one);

	Assertions::assert_true(returnObjects.size() == 0, "There should be no objects that can collide with circle one.");

	//See if I can get_near_shapes collision objects from node 2
	returnObjects.clear();
	quadtree.get_near_shapes(returnObjects, square_two);

	Assertions::assert_true(returnObjects.size() == 5, "There should be 5 objects that can collide with square two.");

	for (int i = 0; i < 5; i++)
	{
		Assertions::assert_true(
			find(returnObjects.begin(),
				returnObjects.end(),
				node_two_objects[i]) != returnObjects.end(), "Should contain nodeTwoObjects: " + i);
	}

	//See if I can get_near_shapes collision objects from node 3
	returnObjects.clear();
	quadtree.get_near_shapes(returnObjects, circle_three);

	Assertions::assert_true(returnObjects.size() == 2, "There should be 2 objects that can collide with circle three.");

	for (int i = 0; i < 2; i++)
	{
		Assertions::assert_true(
			find(returnObjects.begin(),
				returnObjects.end(),
				node_three_objects[i]) != returnObjects.end(), "Should contain nodeThreeObjects: " + i);
	}

	//Clean up
	delete &quadtree;
	delete circle_one;
	delete circle_three;
	delete square_two;
	delete square_zero;
	delete &returnObjects;

	for (int i = 0; i<5; i++)
	{
		delete node_two_objects[i];
	}

	for (int i = 0; i<2; i++)
	{
		delete node_three_objects[i];
	}
}

/*int main()
{
	tests();
	int code = Assertions::getCode();

	if (code != 0)
	{
		cout << Assertions::getErrors();
		system("pause");
		return code;
	}

	cout << "All tests have passed. \n";
	system("pause");
	return 0;
}*/
