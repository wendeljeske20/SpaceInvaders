#include "GameObject.h"



GameObject::GameObject()
{
	position = new Vector2(0, 0);
	scale = new Vector2(1, 1);
	size = scale;
}

GameObject::GameObject(string name, Vector2 *position)
{
	
	this->name = name;
	this->position = position;
	scale = new Vector2(1, 1);
	

}


GameObject::~GameObject()
{
}


void GameObject::Update()
{
	
}

bool GameObject::Colliding(GameObject * other)
{

	return other->position->x < position->x + size->x / 2 &&
		other->position->x > position->x - size->x / 2 &&
		other->position->y < position->y + size->y / 2 &&
		other->position->y > position->y - size->y / 2;
		;
}
void GameObject::SetBuffer()
{
	float scaleAux = 15;
	size = new Vector2((scale->x / scaleAux)  * 2, (scale->y / scaleAux) * 2);
	//size->Print();

	//Vector2 *pointPosition = new Vector2(scale->x / scaleAux + position->x, scale->y / scaleAux + position->y);
	float vertices[] = {
		                         //positions                                                colors        texture coords
		scale->x / scaleAux + position->x, scale->y / scaleAux + position->y, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		scale->x / scaleAux + position->x, -scale->y / scaleAux + position->y, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-scale->x / scaleAux + position->x, -scale->y / scaleAux + position->y, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-scale->x / scaleAux + position->x, scale->y / scaleAux + position->y, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
	};

	unsigned int indexes[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	unsigned int vbo, ebo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);



}


