#pragma once
#include "GameObject.h"
#include "Bullet.h"





class Spaceship : public GameObject
{
public:
	Spaceship();
	Spaceship(GLFWwindow *window, list<GameObject*> *objectList, string name, Vector2 *position);
	~Spaceship();

	GLFWwindow *window;
	list<GameObject*> *objectList;
	int fireRate = 10;
	int nextFireRate = 0;
	float speed = 0.01;
	int damage = 10;
	int maxHealth = 100;
	int currentHealth = maxHealth;

	virtual void Update();
	virtual void Fire(Vector2 *targetPosition, float offSetY);
	void CheckBulletCollisions(bool isPlayerBullet);



};

