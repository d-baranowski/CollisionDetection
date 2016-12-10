#include <iostream>

#include "Quadtree.h"
#include "Circle.h"
#include "MyConstants.h"

using namespace std;

int get_random_value(int max, int min)
{
	return (rand() % (max - min)) + min;
}

/*
 * This creates a random shape on the heap and returns a pointer to it. 
 * It will decide between a circle and a square through a random number,
 * It will decide upon a random size of the shape using MAX_OBJECT_SIDE_LENGTH and MIN_OBJECT_SIDE_LENGTH constans 
 * and then use these values to get a random x and y cordinates within bounds.
 */
Shape * create_random_shape_within_bounds(const Square& bounds)
{
	int type = rand() % 2;

	if (type == square) 
	{
		float sideLength = get_random_value(MAX_OBJECT_SIDE_LENGTH, MIN_OBJECT_SIDE_LENGTH);
		float x = get_random_value(bounds.get_side_length() - sideLength, 0);
		float y = get_random_value(bounds.get_side_length() - sideLength, 0);
		return new Square(x, y, sideLength);
	}
	else if (type == circle)
	{
		float r = get_random_value(MAX_OBJECT_SIDE_LENGTH / 2,MIN_OBJECT_SIDE_LENGTH / 2);
		float x = get_random_value(bounds.get_side_length() - r, r);
		float y = get_random_value(bounds.get_side_length() - r, r);
		return new Circle(x, y, r);
	}

	throw UnsuportedShapeException();
}

void move_to_random_location_within_bounds(Shape* shape, const Square& bounds) {
	float x = get_random_value(bounds.get_width() - shape->get_width(), MIN_MOVE);
	float y = get_random_value(bounds.get_height() - shape->get_height(), MIN_MOVE);
	shape->move_on_x_and_y_to(x,y);
}

void play_game()
{
	//Setup
	Square bounds = Square(0, 0, BOUNDS_SIDE_WIDTH);
	Quadtree environment = Quadtree(0, bounds);
	vector<Shape*> all_shapes = vector<Shape*>();
	vector<Shape*> near_shapes = vector<Shape*>();

	for (int i = 0; i < MAX_OBJECTS_COUNT; i++)
	{
		all_shapes.push_back(create_random_shape_within_bounds(bounds));
	}

	//Game loop
	while (all_shapes.size() > MAX_REMAINING_OBJECTS)
	{
		//Reset quadtree 
		environment.clear();
		for (int i = 0; i < all_shapes.size(); i++)
		{
			environment.insert(all_shapes.at(i));
		}
		
		for (int i = 0; i < all_shapes.size(); i++)
		{
			//Get all objects it can collide with 
			near_shapes.clear();
			environment.get_near_shapes(near_shapes, all_shapes.at(i));

			for (int j = 0; j < near_shapes.size(); j++)
			{
				if (!all_shapes[i]->has_collided)
				{
					if (all_shapes[i]->is_overlaping_with(*near_shapes[j]))
					{
						all_shapes[i]->has_collided = true;
						all_shapes[i]->collided_with = near_shapes[j]->to_string();
						near_shapes[j]->has_collided = true;
						near_shapes[j]->collided_with = all_shapes[i]->to_string();
					}
				}
			}
		}

		for (auto it = all_shapes.begin(); it != all_shapes.end();)
		{
			if ((*it)->has_collided)
			{
				cout << "Removed shape " << (*it)->to_string() << "\n";
				cout << "It has collided with: " << (*it)->collided_with << "\n";
				delete *it;
				it = all_shapes.erase(it);
				cout << "Remaining shapes: " << all_shapes.size() << "\n";
			}
			else {
				++it;
			}
		}

		for (int i = 0; i < all_shapes.size(); i++)
		{
			move_to_random_location_within_bounds(all_shapes[i], bounds);
		}
	}
}

int main()
{
	play_game();
	system("PAUSE");
}