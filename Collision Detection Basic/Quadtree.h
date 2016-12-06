#pragma once
#include "Shape.h"
#include "Rectangle.h"

#include <vector>

using namespace std;

class Quadtree
{
public:
	Quadtree(int level, Rectangle rectangle);
	~Quadtree();
	void clear();
	void insert(Shape* shape);
	void retrieve(vector<Shape*>& returnObjects, Shape* shape);

	//Consider deleating this debug method.
	bool hasBeenSplit() const;

private:
	const int MAX_OBJECTS = 10; //How many objects can I hold before it splits
	const int MAX_LEVELS = 5; //Deepest level subnode

	int level; //Starts with 0 and increments by 1
	vector<Shape*> objects;
	Rectangle bounds;
	Quadtree* nodes[4];

	void split();

	/*
	* Determine which node the object belongs to. -1 means
	* object cannot completely fit within a child node and is part
	* of the parent node
	*/
	int getIndex(Shape* shape) const;
};

