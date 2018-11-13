#pragma once
class Vector3
{
public:

	//Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	float x, y, z;
	static const int a = 5;
	static Vector3 *red, *blue, *green, *yellow, *white, *gray, *black, *orange, *cyan, *magenta;


};

