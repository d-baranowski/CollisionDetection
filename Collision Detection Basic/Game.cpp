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

void moveByRandomAmmountWithinBounds(Shape* shape, Rectangle* bounds) {
	int x = rand() % ((*bounds).getWidth() - (*shape).getWidth());
	int y = rand() % ((*bounds).getHeight() - (*shape).getHeight());
	(*shape).moveOnXandY(x,y);
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
					collidedShapes.push_back(allShapes[i]);
				}
			}
		}

		for (int i = 0; i < collidedShapes.size(); i++)
		{
			allShapes.erase(find(allShapes.begin(), allShapes.end(), collidedShapes[i]));
			cout << "Removed shape " << collidedShapes[i] << "\n";
			cout << "Remaining shapes: " << allShapes.size() << "\n";
			delete collidedShapes[i];
		}
		collidedShapes.clear();

		for (int i = 0; i < allShapes.size(); i++)
		{
			moveByRandomAmmountWithinBounds(allShapes[i], &bounds);
		}
	}

	delete environment;

	system("PAUSE");
}