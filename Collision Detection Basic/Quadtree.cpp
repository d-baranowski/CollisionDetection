#include "Quadtree.h"

using namespace std;

Quadtree::Quadtree(int level, const Square& bounds)
{
	this->level = level;
	this->bounds = bounds;
	//TODO initialize nodes
}


Quadtree::~Quadtree()
{
	for (int i = 0; i < 4; ++i)
	{
		delete nodes[i]; //TODO check if delete runs clear
	}
}

void Quadtree::clear()
{
	objects.clear();

	for (int i = 0 ; i < 4; i++)
	{
		if (nodes[i] != nullptr)
		{
			(nodes[i])->clear(); //TODO check if delete runs clear
			delete nodes[i];
			nodes[i] = nullptr;
		}
	}
}

void Quadtree::insert(Shape* shape)
{
	if (nodes[0] != nullptr) {
		int index = getIndex(shape);

		if (index != -1) {
			(nodes[index])->insert(shape);

			return;
		}
	}

	objects.push_back(shape);

	if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS) {
		if (nodes[0] == nullptr) {
			split();
		}

		int i = 0;
		while (i < objects.size()) {
			int index = getIndex(objects.at(i));
			if (index != -1) {
				(nodes[index])->insert(objects.at(i));
				objects.erase(objects.begin() + i);
			}
			else {
				i++;
			}
		}
	}
}

void Quadtree::get_near_shapes(vector<Shape*>& returnObjects, Shape* shape)
{
	const int index = getIndex(shape);
	if (index != -1 && nodes[0] != nullptr)
	{
		(nodes[index])->get_near_shapes(returnObjects, shape);
	}

	//Add all of objects of this node to the list.
	for (int i = 0; i < objects.size(); i++)
	{
		//Can't collide with itself
		if (objects[i] != shape)
		{
			returnObjects.push_back(objects[i]);
		}
	}
}

void Quadtree::split()
{
	const float subWidth = bounds.get_width() / 2;
	const float subHeight = bounds.get_height() / 2;
	
	nodes[0] = new Quadtree(level + 1, Square(bounds.get_x_pos() + subWidth, bounds.get_y_pos(), subWidth, subHeight));
	nodes[1] = new Quadtree(level + 1, Square(bounds.get_x_pos(), bounds.get_y_pos(), subWidth, subHeight));
	nodes[2] = new Quadtree(level + 1, Square(bounds.get_x_pos(), bounds.get_y_pos() + subHeight, subWidth, subHeight));
	nodes[3] = new Quadtree(level + 1, Square(bounds.get_x_pos() + subWidth, bounds.get_y_pos() + subHeight, subWidth, subHeight));
}

/**
* QuadTree object.
*
* The quadrant indexes are numbered as below:
*     |
*  1  |  0
* —-+—-
*  2  |  3
*     |
*/
int Quadtree::getIndex(Shape* shape) const
{
	int index = -1;
	const float verticalMidpoint = bounds.get_x_pos() + (bounds.get_width() / 2);
	const float horizontalMidpoint = bounds.get_y_pos() + (bounds.get_height() / 2);

	//Object can completely fit within the top quadrants
	const bool topQuadrant = (*shape).get_y_pos() < horizontalMidpoint && (*shape).get_y_pos() + (*shape).get_height();
	const bool bottomQuadrant = (*shape).get_y_pos() > horizontalMidpoint;

	// Object can completely fit within the left quadrants
	if ((*shape).get_x_pos() < verticalMidpoint && (*shape).get_x_pos() + (*shape).get_width() < verticalMidpoint) {
		if (topQuadrant) {
			index = 1;
		}
		else if (bottomQuadrant) {
			index = 2;
		}
	}

	// Object can completely fit within the right quadrants
	else if ((*shape).get_x_pos() > verticalMidpoint) {
		if (topQuadrant) {
			index = 0;
		}
		else if (bottomQuadrant) {
			index = 3;
		}
	}

	return index;
}