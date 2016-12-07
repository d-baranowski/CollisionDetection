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

int main()
{
	Rectangle bounds = Rectangle(0, 0, 1200, 1200);
	Quadtree* environment = new Quadtree(0, bounds);
	vector<Shape*> allShapes;
	vector<Shape*> collidedShapes;

	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		allShapes.push_back(getRandomShapeWithinBounds(bounds));
	}

	//Let the game begin
	vector<Shape*> returnObjects;

	while (allShapes.size() > 0)
	{
		//Reset quadtree 
		(*environment).clear();
		for (int i = 0; i < allShapes.size(); i++)
		{
			(*environment).insert(allShapes.at(i));
		}
		//

		for (int i = 0; i < allShapes.size(); i++)
		{
			//Get all objects allShapes[i] can collide with 
			returnObjects.clear();
			(*environment).retrieve(returnObjects, allShapes.at(i));

			for (int j = 0; j < returnObjects.size(); j++)
			{
				if (allShapes[i]->isOverlapingWith(*returnObjects[j]))
				{
					collidedShapes.push_back(allShapes[i]);
				}
			}
		}

		for (int i = 0; i < collidedShapes.size(); i++)
		{
			delete collidedShapes[i];
		}

		for (int i = 0; i < allShapes.size(); i++)
		{
			Shape* test = allShapes.at(i);
			if (test == nullptr)
			{
				allShapes.erase(allShapes.begin() + i);
			}
		}
	}


	delete environment;

	system("PAUSE");
}