#include "GameObject.h"



GameObject::GameObject()
{
	position = Vector2::zero;
	scale = Vector2::one;
	size = scale;
}

GameObject::GameObject(string name, Vector2 *position)
{
	
	this->name = name;
	this->position = position;
	scale = Vector2::one;
	textureName = "container.jpg";

}


GameObject::~GameObject()
{
}


void GameObject::Update()
{
	SetBuffer();
}

bool GameObject::Colliding(GameObject * other)
{

	return other->position->x + other->size->x / 2 > position->x - size->x / 2 &&
		other->position->x - other->size->x / 2 < position->x + size->x / 2 &&
		other->position->y + other->size->y / 2 > position->y - size->x / 2 &&
		other->position->y - other->size->y / 2 < position->y + size->x / 2 ;
		
		
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

void GameObject::SetTexture()
{


	// load and create a texture
	// -------------------------

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;

	//stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(textureName, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK);		// cull back face
	glFrontFace(GL_CW);			// GL_CCW for counter clock-wise

}

