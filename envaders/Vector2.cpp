#include "Vector2.h"


Vector2* Vector2::one = new Vector2(1, 1);
Vector2* Vector2::zero = new Vector2(0, 0);

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::Print()
{
	cout << "(" << x << "," << y << "}" << endl;
}


