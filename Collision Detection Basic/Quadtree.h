#pragma once
#include "Shape.h"
#include "Rectangle.h"

class Quadtree
{
public:
	Quadtree();
	~Quadtree();

private:
	const int MAX_OBJECTS = 10;
	const int MAX_LEVELS = 5;

	const int level;
	Shape objects [10];
	const Rectangle bounds;
};

