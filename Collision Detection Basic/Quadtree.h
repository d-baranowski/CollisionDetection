#pragma once
#include "Shape.h"
#include "Square.h"

#include <vector>

using namespace std;

class Quadtree
{
public:
	Quadtree(int level, const Square& rectangle);
	~Quadtree();
	void clear();
	void insert(Shape* shape);
	void get_near_shapes(vector<Shape*>& return_objects, Shape* shape);

private:
	const int MAX_OBJECTS = 10; //How many objects can I hold before it splits
	const int MAX_LEVELS = 5; //Deepest level subnode

	int level; //Starts with 0 and increments by 1
	vector<Shape*> objects;
	Square bounds;
	Quadtree* nodes[4];

	void split();

	/*
	* Determine which node the object belongs to. -1 means
	* object cannot completely fit within a child node and is part
	* of the parent node
	*/
	int getIndex(Shape* shape) const;
};

