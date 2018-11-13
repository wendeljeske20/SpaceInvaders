#include "Spaceship.h"




Spaceship::Spaceship()
{
}

Spaceship::Spaceship(GLFWwindow * window, list<GameObject*> *objectList, string name, Vector2 *position)
{
	this->window = window;
	this->objectList = objectList;
	this->name = name;
	this->position = position;



}

Spaceship::~Spaceship()
{
}

void Spaceship::Update()
{
	GameObject::Update();


}

void Spaceship::Fire(Vector2 *targetPosition, float offSetY)
{
	Bullet *bullet = new Bullet(objectList, new Vector2(position->x, position->y + offSetY));
	bullet->SetTargetPosition(targetPosition);
	bullet->scale = new Vector2(0.3, 0.3);
	objectList->push_back(bullet);


}


