#include "Bullet.h"



Bullet::Bullet(list<GameObject*> *objectList, Vector2 *position)
{
	
	this->objectList = objectList;
	this->position = position;
	startPosition = position;
	name = "bullet";
	
	textureName = "container.jpg";
	SetTexture();
}


Bullet::~Bullet()
{
}


void Bullet::Update()
{
	GameObject::Update();

	Follow();


	//list<GameObject*>::iterator findIter = std::find(objectList->begin(), objectList->end(), this);
	//GameObject *thisObj = *findIter;

	//if (position->y > 0 && !test)
	//{
	//	//objectList->remove(objectList->front());
	//	//cout << thisObj->name << " ";
	//	test = true;


	//	objectList->erase(findIter++);
	//
	//	
	//	//delete thisObj;
	//	//thisObj = nullptr;
	//	//cout << "morreu";

	//	test = true;
	//	return;
	//}



}

void Bullet::SetTargetPosition(Vector2 *targetPosition, bool isPlayerBullet)
{

	this->targetPosition = targetPosition;
	this->isPlayerBullet = isPlayerBullet;
	GameObject::Update();
	
	float angle = atan2(targetPosition->x - startPosition->x, targetPosition->y - startPosition->y);
	 angularSpeed = new Vector2(speed * sin(angle), speed * cos(angle));
	

}

void Bullet::Follow()
{
	

	//cout << "(" << to_string(targetPosition->x - startPosition->x) << "," << to_string(targetPosition->y - startPosition->y) << "}" << endl;

	position->x += angularSpeed->x;
	position->y += angularSpeed->y;
	
}



