#include "Vector2.h"




Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::Print()
{
	cout << "(" << x << "," << y << "}" << endl;
}


