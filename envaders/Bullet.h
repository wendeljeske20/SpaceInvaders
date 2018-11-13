#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(list<GameObject*> *objectList, Vector2 *position);
	~Bullet();

	Vector2 *targetPosition;
	Vector2 *startPosition;

	list<GameObject*> *objectList;
	float speed = 0.015;
	bool test = false;
	Vector2 *angularSpeed;
	

	void Update();
	void SetTargetPosition(Vector2 *targetPosition);
	void Follow();


};

