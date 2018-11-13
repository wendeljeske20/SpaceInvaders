#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

#include <iostream>
#include <string>

#include "Vector2.h"
#include "Vector3.h"
#include <list>
//#include <stack>
#include <time.h>
#include <algorithm>    // std::find
#include <string>

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(string name, Vector2 *position);
	~GameObject();

	Vector2 *position;
	Vector2 *scale;
	Vector2 *size;
	string name = "undefined";
	GLfloat *points = new GLfloat[9];
	
	GLuint vao;

	
	
	
	
	virtual void Update();

	void SetBuffer();
	bool Colliding(GameObject *other);



};

