#pragma once
class Shape
{
public:
	Shape(int x, int y);
	int getXPos()  const;
	int getYPos()  const;

	void moveOnXBy(int num);
	void moveOnYBy(int num);
	void moveOnXandY(int x, int y);

private:
	int state[2];
};

