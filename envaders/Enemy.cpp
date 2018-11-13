#include "Enemy.h"



Enemy::Enemy(GLFWwindow * window, list<GameObject*>* objectList, string name, Vector2 *position)
{
	srand(time(NULL));
	//Spaceship::Spaceship(window, objectList,name,  position);

	this->window = window;
	this->objectList = objectList;
	this->name = name;
	this->position = position;


	targetPosition = new Vector2(0, 0);
	fireRate = 150;
	textureName = "spaceshuttle.jpg";
	SetTexture();

}


Enemy::~Enemy()
{
}

void Enemy::SetTargetPosition(Vector2 * targetPosition)
{
	this->targetPosition = targetPosition;
}

void Enemy::Fire(Vector2 * targetPosition, float offSetY)
{
	Bullet *bullet = new Bullet(objectList, new Vector2(position->x, position->y + offSetY));
	bullet->SetTargetPosition(targetPosition, false);
	bullet->scale = new Vector2(0.3, 0.3);
	objectList->push_back(bullet);
}
 

void Enemy::Update()
{
	Spaceship::Update();
	//cout << targetPosition->x << ", " << targetPosition->y << endl;

	nextFireRate++;
	//int random = rand() % 200 + 800;
	//cout << random << endl;
	//if (nextFireRate >= random) {
		//Fire(targetPosition, -0.1);
		//nextFireRate = 0;
	//}

	//BUG
	list<GameObject*>::iterator it = objectList->begin();

	//list<GameObject*>::iterator findIter = find(objectList->begin(), objectList->end(), this);


	GameObject *otherObj = *it;
	//GameObject *thisGo = *findIter;

	if (otherObj && Colliding(otherObj) && !test)
	{
		//	
		//	//objectList->remove(thisGo);
		//	//delete this;
		//
		objectList->remove(otherObj);
		//	
		//
		cout << "collidiu";


		test = true;

	}

	/*for (std::list<GameObject*>::iterator it = objectList->begin(); it != objectList->end(); ++it)
	{
		GameObject *otherObj = *it;

		if (Colliding(otherObj) && !test)
		{
			objectList->remove(otherObj);
			test = true;
		}
	}*/


	CheckBulletCollisions(true);

	//for (std::list<GameObject*>::iterator it = objectList->begin(); it != objectList->end(); ++it)
	//{
	//	GameObject *otherObj = *it;

	//	if (otherObj)
	//	{
	//		if (Bullet* b = dynamic_cast<Bullet*>(otherObj))
	//		{
	//			if (Colliding(b) && b->isPlayerBullet)
	//			{
	//				
	//				objectList->remove(b);
	//				delete b;
	//				b = nullptr;

	//				//cout << "collidiu";
	//				currentHealth -= 40;
	//				
	//				break;
	//			}

	//		}
	//	}
	//	
	//}
}
