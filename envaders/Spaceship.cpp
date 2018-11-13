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
	/*Bullet *bullet = new Bullet(objectList, new Vector2(position->x, position->y + offSetY), targetPosition);
	bullet->SetTargetPosition(targetPosition, );
	bullet->scale = new Vector2(0.3, 0.3);
	objectList->push_back(bullet);*/


}

void Spaceship::CheckBulletCollisions(bool isPlayerBullet)
{
	for (std::list<GameObject*>::iterator it = objectList->begin(); it != objectList->end(); ++it)
	{
		GameObject *otherObj = *it;

		if (otherObj)
		{
			if (Bullet* b = dynamic_cast<Bullet*>(otherObj))
			{
				if (Colliding(b) && b->isPlayerBullet == isPlayerBullet)
				{

					objectList->remove(b);
					delete b;
					b = nullptr;

					//cout << "collidiu";
					currentHealth -= 40;

					break;
				}

			}
		}

	}
}


