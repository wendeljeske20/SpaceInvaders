#pragma once
#include "Spaceship.h"

class Enemy : public Spaceship
{
public:
	Enemy(GLFWwindow * window, list<GameObject*>* objectList, string name, Vector2 *position);
	~Enemy();

	Vector2 *targetPosition;
	void SetTargetPosition(Vector2 *targetPosition);
	void Update();

	bool test = false;

};

