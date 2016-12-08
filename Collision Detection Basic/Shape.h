#pragma once
class Shape
{
public:
	Shape(float x, float y, float w, float h);
	virtual ~Shape();
	float getXPos()  const;
	float getYPos()  const;
	float getHeight() const;
	float getWidth() const;
	
	void moveOnXTo(float num);
	void moveOnYTo(float num);
	void moveOnXandY(float x, float y);

	bool hasCollided = false;
	virtual bool isOverlapingWith(Shape shape);
protected:
	int state[4];
};

