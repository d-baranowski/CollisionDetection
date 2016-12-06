#pragma once
class Shape
{
public:
	virtual ~Shape()
	{
	}

	Shape(int x, int y, int w, int h);
	int getXPos()  const;
	int getYPos()  const;
	int getHeight() const;
	int getWidth() const;
	

	void moveOnXBy(int num);
	void moveOnYBy(int num);
	void moveOnXandY(int x, int y);

private:
	int state[4];
};

