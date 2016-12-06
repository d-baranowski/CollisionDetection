#include <iostream>
#include "Quadtree.h"
#include "Circle.h"

using namespace std;

Shape * getRandomShapeWithinBounds(Rectangle bounds)
{
	Shape * shape;
	int type = rand() % 2;

	if (type == 1)
	{
		int width = rand() % 30;
		int height = rand() % 30;
		int x = rand() % (bounds.getWidth() - width);
		int y = rand() % (bounds.getHeight() - height);
		shape = new Rectangle(x, y, width, height);
	}
	else
	{
		int r = rand() % 15;
		int x = rand() % (bounds.getWidth() - (2 * r));
		int y = rand() % (bounds.getHeight() - (2 * r));
		shape = new Circle(x, y, r);
	}

	return shape;
}

const int MAX_OBJECTS = 100;

/*int main()
{
	Rectangle bounds = Rectangle(0, 0, 1200, 1200);
	Quadtree* environment = new Quadtree(0, bounds);
	vector<Shape*> allShapes;

	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		allShapes.push_back(getRandomShapeWithinBounds(bounds));
	}

	//Let the game begin

	while (allShapes.size() > 0)
	{
		(*environment).clear();
		for (int i = 0; i < allShapes.size(); i++) {
			(*environment).insert(allShapes.at(i));
		}

		vector<Shape*> returnObjects;

		for (int i = 0; i < allShapes.size(); i++) {
			returnObjects.clear();
			(*environment).retrieve(returnObjects, allShapes.at(i));

			for (int j = 0; j < returnObjects.size(); j++) {
				// Run collision detection algorithm between objects
			}
		}
	}

	delete environment;

	system("PAUSE");
}*/