#pragma once
#include "Spaceship.h"
#include "Bullet.h"

class Enemy : public Spaceship
{
public:
	Enemy(GLFWwindow * window, list<GameObject*>* objectList, string name, Vector2 *position);
	~Enemy();

	Vector2 *targetPosition;
	void SetTargetPosition(Vector2 *targetPosition);
	void Update();
	void Fire(Vector2 *targetPosition, float offSetY);
	bool test = false;

};

