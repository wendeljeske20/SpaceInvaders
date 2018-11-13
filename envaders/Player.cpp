#include "Player.h"






Player::Player(GLFWwindow * window, list<GameObject*>* objectList, string name, Vector2 *position)
{
	//Player::Spaceship(window, objectList, name, position);
	this->window = window;
	this->objectList = objectList;
	this->name = name;
	this->position = position;


	fireRate = 30;


}

Player::~Player()
{
}

void Player::Update()
{
	Spaceship::Update();
	MoveControls();
	// cout << position->x << ", " << position->y << endl;

	nextFireRate++;
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_SPACE) && nextFireRate >= fireRate) {
		Fire(new Vector2(position->x, 0.5), 0.1);
		nextFireRate = 0;
	}

	//position->Print();
}


void Player::MoveControls()
{
	//glm::translate()



	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_A)) {
		position->x -= speed;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_D)) {

		position->x += speed;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_W)) {
		position->y += speed;
	}
	if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_S)) {
		position->y -= speed;
	}


}


