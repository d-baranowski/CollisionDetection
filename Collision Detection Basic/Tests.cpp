#include "Assertions.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
#include "Quadtree.h"

void tests()
{
	//Rectangle
	Assertions::assertTrue(Rectangle(170, 139, 177, 130)
		.isOverlapingWith(Rectangle(106, 83, 101, 102)),
		"These squares should overlap");
	Assertions::assertTrue(!Rectangle(178, 98, 96, 90)
		.isOverlapingWith(Rectangle(380, 81, 101, 102)),
		"These squares should not overlap");
	//Circle
	Assertions::assertTrue(Circle(171, 309, 43)
		.isOverlapingWith(Circle(128, 301, 36)),
		"These circles should overlap");
	Assertions::assertTrue(!Circle(171, 309, 43)
		.isOverlapingWith(Circle(263, 279, 36))
		, "These circles should not overlap");

	//Circle / Rectangle
	Assertions::assertTrue(Circle(166, 204, 36).isOverlapingWith(Rectangle(178, 98, 96, 90)),
		"This circle should overlap with this rectangle");
	Assertions::assertTrue(!(Circle(145, 78, 36).isOverlapingWith(Rectangle(178, 98, 96, 90))),
		"This circle should not overlap with this rectangle");

	//Quadtree
	Quadtree& quadtree = *new Quadtree(0, Rectangle(0, 0, 200, 200));
	Shape * circleOne = new Circle(49, 49, 8);
	Shape * squareZero = new Rectangle(143, 38, 20, 20);
	Shape * squareTwo = new Rectangle(40, 136, 20, 20);
	Shape * circleThree = new Circle(155, 150, 9);

	//Can insert into quadtree
	quadtree.insert(circleOne);
	quadtree.insert(squareZero);
	quadtree.insert(squareTwo);
	quadtree.insert(circleThree);

	vector<Shape*>& returnObjects = *new vector<Shape*>;

	quadtree.retrieve(returnObjects, circleOne);

	Assertions::assertTrue(
		find(returnObjects.begin(),
			returnObjects.end(),
			squareZero) != returnObjects.end(), "Should contain square zero.");

	Assertions::assertTrue(
		find(returnObjects.begin(),
			returnObjects.end(),
			squareTwo) != returnObjects.end(), "Should contain square two.");

	Assertions::assertTrue(
		find(returnObjects.begin(),
			returnObjects.end(),
			circleThree) != returnObjects.end(), "Should contain circle three.");

	//Add more objects so the quadtree splits
	Shape * nodeTwoObjects[5] = {
		new Circle(12, 119, 6),
		new Circle(37, 113, 6),
		new Circle(77, 121, 6),
		new Circle(16, 141, 6),
		new Circle(64, 179, 6)
	};

	Shape * nodeThreeObjects[2] = {
		new Rectangle(119,116,20,20),
		new Rectangle(165,108,20,20)
	};

	for (int i = 0; i<5; i++)
	{
		quadtree.insert(nodeTwoObjects[i]);
		if (i < 2)
		{
			quadtree.insert(nodeThreeObjects[i]);
		}
	}

	Assertions::assertTrue(quadtree.hasBeenSplit(), "The tree should have been split.");

	//See if I can retrieve collision objects from node 0
	returnObjects.clear();
	quadtree.retrieve(returnObjects, squareZero);

	Assertions::assertTrue(returnObjects.size() == 0, "There should be no objects that can collide with square zero.");

	//See if I can retrieve collision objects from node 1
	returnObjects.clear();
	quadtree.retrieve(returnObjects, circleOne);

	Assertions::assertTrue(returnObjects.size() == 0, "There should be no objects that can collide with circle one.");

	//See if I can retrieve collision objects from node 2
	returnObjects.clear();
	quadtree.retrieve(returnObjects, squareTwo);

	Assertions::assertTrue(returnObjects.size() == 5, "There should be 5 objects that can collide with square two.");

	for (int i = 0; i < 5; i++)
	{
		Assertions::assertTrue(
			find(returnObjects.begin(),
				returnObjects.end(),
				nodeTwoObjects[i]) != returnObjects.end(), "Should contain nodeTwoObjects: " + i);
	}

	//See if I can retrieve collision objects from node 3
	returnObjects.clear();
	quadtree.retrieve(returnObjects, circleThree);

	Assertions::assertTrue(returnObjects.size() == 2, "There should be 2 objects that can collide with circle three.");

	for (int i = 0; i < 2; i++)
	{
		Assertions::assertTrue(
			find(returnObjects.begin(),
				returnObjects.end(),
				nodeThreeObjects[i]) != returnObjects.end(), "Should contain nodeThreeObjects: " + i);
	}

	//Clean up
	delete &quadtree;
	delete circleOne;
	delete circleThree;
	delete squareTwo;
	delete squareZero;
	delete &returnObjects;

	for (int i = 0; i<5; i++)
	{
		delete nodeTwoObjects[i];
	}

	for (int i = 0; i<2; i++)
	{
		delete nodeThreeObjects[i];
	}
}

int main()
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
}
