#pragma once
#include "Spaceship.h"


class Player : public Spaceship
{
public:

	Player(GLFWwindow *window, list<GameObject*> *objectList, string name, Vector2 *position);
	~Player();

	void Update();
	void Fire(Vector2 *targetPosition, float offSetY);
	void MoveControls();
};

