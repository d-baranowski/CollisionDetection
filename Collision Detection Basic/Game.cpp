#include <iostream>

#include "Quadtree.h"
#include "Circle.h"
#include "MyConstants.h"

using namespace std;

int get_random_value(int max, int min)
{
	return (rand() % (max - min)) + min;
}

Shape * get_random_shape_within_bounds(Rectangle bounds)
{
	Shape * shape;
	int type = rand() % 2;

	if (type == 1)
	{
		float width = get_random_value(MAX_OBJECT_WIDTH, MIN_OBJECT_WIDTH);
		float height = get_random_value(MAX_OBJECT_HEIGHT, MIN_OBJECT_HEIGHT);
		float x = get_random_value(bounds.get_width() - width, 0);
		float y = get_random_value(bounds.get_height() - height,0);
		shape = new Rectangle(x, y, width, height);
	}
	else
	{
		float r = get_random_value(MAX_OBJECT_WIDTH,MIN_OBJECT_WIDTH) / 2;
		float x = get_random_value(bounds.get_width() - (2 * r), 0);
		float y = get_random_value(bounds.get_height() - (2 * r), 0);
		shape = new Circle(x, y, r);
	}

	return shape;
}

void move_to_random_location_within_bounds(Shape* shape, Rectangle* bounds) {
	float x = get_random_value(bounds->get_width() - shape->get_width(), 0);
	float y = get_random_value(bounds->get_height() - shape->get_height(), 0);
	(*shape).move_on_x_and_y_to(x,y);
}

void play_game()
{
	//Setup
	Rectangle bounds = Rectangle(0, 0, BOUNDS_WIDTH, BOUNDS_HEIGHT);
	Quadtree* environment = new Quadtree(0, bounds);
	vector<Shape*> all_shapes;
	vector<Shape*> near_shapes;

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		all_shapes.push_back(get_random_shape_within_bounds(bounds));
	}

	//Game loop
	while (all_shapes.size() > MAX_REMAINING_OBJECTS)
	{
		//Reset quadtree 
		(*environment).clear();
		for (int i = 0; i < all_shapes.size(); i++)
		{
			(*environment).insert(all_shapes.at(i));
		}
		
		for (int i = 0; i < all_shapes.size(); i++)
		{
			//Get all objects it can collide with 
			near_shapes.clear();
			(*environment).get_near_shapes(near_shapes, all_shapes.at(i));

			for (int j = 0; j < near_shapes.size(); j++)
			{
				if (all_shapes[i]->is_overlaping_with(*near_shapes[j]))
				{
					all_shapes[i]->has_collided_ = true;
					near_shapes[j]->has_collided_ = true;
				}
			}
		}

		for (int i = 0; i < all_shapes.size(); i++)
		{
			if (all_shapes[i]->has_collided_)
			{
				cout << "Removed shape " << all_shapes[i] << "\n";
				delete all_shapes[i];
				all_shapes.erase(all_shapes.begin() + i);
				cout << "Remaining shapes: " << all_shapes.size() << "\n";
			}
		}

		for (int i = 0; i < all_shapes.size(); i++)
		{
			move_to_random_location_within_bounds(all_shapes[i], &bounds);
		}
	}

	delete environment;

	system("PAUSE");
}

int main()
{
	play_game();
}