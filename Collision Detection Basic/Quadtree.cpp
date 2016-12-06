#include "Quadtree.h"

using namespace std;

Quadtree::Quadtree(int level, Rectangle bounds) 
{
	this->level = level;
	this->bounds = bounds;
}


Quadtree::~Quadtree()
{
	for (int i = 0; i < 4; ++i)
	{
		delete nodes[i];
	}
}

void Quadtree::clear()
{
	objects.clear();

	for (int i = 0 ; i < 4; i++)
	{
		if (nodes[i] != nullptr)
		{
			(nodes[i])->clear();
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
				//objects.erase(i);
				objects.erase(objects.begin() + i);
			}
			else {
				i++;
			}
		}
	}
}

void Quadtree::retrieve(vector<Shape*>& returnObjects, Shape* shape)
{
	const int index = getIndex(shape);
	if (index != -1 && nodes[0] != nullptr)
	{
		(nodes[index])->retrieve(returnObjects, shape);
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

bool Quadtree::hasBeenSplit() const
{
	return nodes[0] != nullptr;
}

void Quadtree::split()
{
	const int subWidth = bounds.getWidth() / 2;
	const int subHeight = bounds.getHeight() / 2;
	
	nodes[0] = new Quadtree(level + 1, Rectangle(bounds.getXPos() + subWidth, bounds.getYPos(), subWidth, subHeight));
	nodes[1] = new Quadtree(level + 1, Rectangle(bounds.getXPos(), bounds.getYPos(), subWidth, subHeight));
	nodes[2] = new Quadtree(level + 1, Rectangle(bounds.getXPos(), bounds.getYPos() + subHeight, subWidth, subHeight));
	nodes[3] = new Quadtree(level + 1, Rectangle(bounds.getXPos() + subWidth, bounds.getYPos() + subHeight, subWidth, subHeight));
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
	const float verticalMidpoint = bounds.getXPos() + (bounds.getWidth() / 2);
	const float horizontalMidpoint = bounds.getYPos() + (bounds.getHeight() / 2);

	//Object can completely fit within the top quadrants
	const bool topQuadrant = (*shape).getYPos() < horizontalMidpoint && (*shape).getYPos() + (*shape).getHeight();
	const bool bottomQuadrant = (*shape).getYPos() > horizontalMidpoint;

	// Object can completely fit within the left quadrants
	if ((*shape).getXPos() < verticalMidpoint && (*shape).getXPos() + (*shape).getWidth() < verticalMidpoint) {
		if (topQuadrant) {
			index = 1;
		}
		else if (bottomQuadrant) {
			index = 2;
		}
	}

	// Object can completely fit within the right quadrants
	else if ((*shape).getXPos() > verticalMidpoint) {
		if (topQuadrant) {
			index = 0;
		}
		else if (bottomQuadrant) {
			index = 3;
		}
	}

	return index;
}