#include "Vector3.h"


Vector3* Vector3::red = new Vector3(1, 0, 0);
Vector3* Vector3::green = new Vector3(0, 1, 0);
Vector3* Vector3::blue = new Vector3(0, 0, 1);
Vector3* Vector3::white = new Vector3(1, 1, 1);
Vector3* Vector3::gray = new Vector3(0.5, 0.5, 0.5);
Vector3* Vector3::black = new Vector3(0, 0, 0);
Vector3* Vector3::yellow = new Vector3(1, 1, 0);
Vector3* Vector3::orange = new Vector3(1, 0.5, 0);
Vector3* Vector3::cyan = new Vector3(0, 1, 1);
Vector3* Vector3::magenta = new Vector3(1, 0, 1);



Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}


Vector3::~Vector3()
{
}



