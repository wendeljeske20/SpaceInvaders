#include "Bullet.h"



Bullet::Bullet(list<GameObject*> *objectList, Vector2 *position)
{
	targetPosition = new Vector2(0, 0);

	this->position = position;
	startPosition = position;
	name = "bullet";

	this->objectList = objectList;


}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	GameObject::Update();

	Follow();


	list<GameObject*>::iterator findIter = std::find(objectList->begin(), objectList->end(), this);
	GameObject *thisObj = *findIter;

	if (position->y > 0 && objectList->size() > 1 && !test)
	{
		//objectList->remove(objectList->front());
		//cout << thisObj->name << " ";
		test = true;


	}



}

void Bullet::SetTargetPosition(Vector2 *targetPosition)
{

	this->targetPosition = targetPosition;
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

