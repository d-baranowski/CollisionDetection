#pragma once
class Shape
{
public:
	Shape(int x, int y, int w, int h);
	virtual ~Shape();
	int getXPos()  const;
	int getYPos()  const;
	int getHeight() const;
	int getWidth() const;
	
	void moveOnXBy(int num);
	void moveOnYBy(int num);
	void moveOnXandY(int x, int y);

	virtual bool isOverlapingWith(Shape shape);


protected:
	int state[4];
};

