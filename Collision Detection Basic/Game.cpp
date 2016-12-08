#include <iostream>
#include <algorithm>
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
		int x = rand() % static_cast<int>(bounds.getWidth() - width);
		int y = rand() % static_cast<int>(bounds.getHeight() - height);
		shape = new Rectangle(x, y, width, height);
	}
	else
	{
		int r = rand() % 15;
		int x = rand() % static_cast<int>(bounds.getWidth() - (2 * r));
		int y = rand() % static_cast<int>(bounds.getHeight() - (2 * r));
		shape = new Circle(x, y, r);
	}

	return shape;
}

void moveByRandomAmmountWithinBounds(Shape* shape, Rectangle* bounds) {
	int x = rand() % static_cast<int>((*bounds).getWidth() - (*shape).getWidth());
	int y = rand() % static_cast<int>((*bounds).getHeight() - (*shape).getHeight());
	(*shape).moveOnXandY(x,y);
}

const int MAX_OBJECTS = 100;

int main()
{
	Rectangle bounds = Rectangle(0, 0, 1200, 1200);
	Quadtree* environment = new Quadtree(0, bounds);
	vector<Shape*> allShapes;

	for (int i = 0; i < MAX_OBJECTS; i++)
	{
		allShapes.push_back(getRandomShapeWithinBounds(bounds));
	}

	//Let the game begin
	vector<Shape*> returnObjects;

	while (allShapes.size() > 1)
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
					allShapes[i]->hasCollided = true;
					returnObjects[j]->hasCollided = true;
				}
			}
		}

		for (int i = 0; i < allShapes.size(); i++)
		{
			if (allShapes[i]->hasCollided)
			{
				cout << "Removed shape " << allShapes[i] << "\n";
				delete allShapes[i];
				allShapes.erase(allShapes.begin() + i);
				cout << "Remaining shapes: " << allShapes.size() << "\n";
			}
		}

		for (int i = 0; i < allShapes.size(); i++)
		{
			moveByRandomAmmountWithinBounds(allShapes[i], &bounds);
		}
	}

	delete environment;

	system("PAUSE");
}