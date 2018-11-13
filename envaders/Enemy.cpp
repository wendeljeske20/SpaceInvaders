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
	fireRate = 200;

}


Enemy::~Enemy()
{
}

void Enemy::SetTargetPosition(Vector2 * targetPosition)
{
	this->targetPosition = targetPosition;
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

	if (Colliding(otherObj) && !test)
	{
		//	
		//	//objectList->remove(thisGo);
		//	//delete this;
		//
		//objectList->remove(otherObj);
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

}
