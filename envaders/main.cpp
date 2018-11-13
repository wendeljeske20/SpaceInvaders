
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define GL_LOG_FILE "gl.log"
#include <iostream>
#include "gl_utils.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Player.h"
#include "Enemy.h"
#include <list>
#include <iostream>
using namespace std;

int g_gl_width = 768;
int g_gl_height = 768;
GLFWwindow *g_window = NULL;

list<GameObject*> *objectList = new list<GameObject*>();
int printRate = 40;
int nextPrintRate = 0;


unsigned int texture;
GLuint shader_programme;

void PrintList()
{
	nextPrintRate++;
	if (nextPrintRate == printRate)
	{
		cout << "---------------------------" << endl;
		for (std::list<GameObject*>::iterator it = objectList->begin(); it != objectList->end(); ++it)
		{
			GameObject *obj = *it;
			cout << "[" + to_string(distance(objectList->begin(), it)) + "] " + obj->name << endl;
		}
		nextPrintRate = 0;
	}
}
void Texture()
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
	unsigned char *data = stbi_load("spaceshuttle.jpg", &width, &height, &nrChannels, 0);
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

int Shader()
{

	char vertex_shader[1024 * 256];
	char fragment_shader[1024 * 256];
	parse_file_into_str("test_vs.glsl", vertex_shader, 1024 * 256);
	parse_file_into_str("test_fs.glsl", fragment_shader, 1024 * 256);

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	const GLchar *p = (const GLchar *)vertex_shader;
	glShaderSource(vs, 1, &p, NULL);
	glCompileShader(vs);

	// check for compile errors
	int params = -1;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: GL shader index %i did not compile\n", vs);
		print_shader_info_log(vs);
		return 1; // or exit or something
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	p = (const GLchar *)fragment_shader;
	glShaderSource(fs, 1, &p, NULL);
	glCompileShader(fs);

	// check for compile errors
	glGetShaderiv(fs, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: GL shader index %i did not compile\n", fs);
		print_shader_info_log(fs);
		return 1; // or exit or something
	}

	shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	glGetProgramiv(shader_programme, GL_LINK_STATUS, &params);
	if (GL_TRUE != params) {
		fprintf(stderr, "ERROR: could not link shader programme GL index %i\n",
			shader_programme);
		print_programme_info_log(shader_programme);
		return false;
	}

}

void Draw(int vao)
{
	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int main() {

	restart_gl_log();
	// all the GLFW and GLEW start-up code is moved to here in gl_utils.cpp
	start_gl("Space Invaders");
	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	//glEnable( GL_DEPTH_TEST ); // enable depth-testing
	//glDepthFunc( GL_LESS );		 // depth-testing interprets a smaller value as "closer"

	Player *player = new Player(g_window, objectList, "player", new Vector2(0, -0.8));
	//player->SetColors(Vector3::cyan);
	objectList->push_back(player);
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{

			Enemy *enemy = new Enemy(g_window, objectList, "enemy", new Vector2(-0.6 + (i * 0.3), 0.7 - (j * 0.3)));


			objectList->push_back(enemy);
		}
	}

	/*GameObject *horizontalLine = new GameObject("horizontal line", new Vector2(0, 0));
	horizontalLine->scale = new Vector2(20, 0.03);
	objectList->push_back(horizontalLine);

	GameObject *verticalLine = new GameObject("vertical line", new Vector2(0, 0));
	verticalLine->scale = new Vector2(0.03, 20);
	objectList->push_back(verticalLine);*/

	/*for (int i = 0; i < 3; i++)
	{
		GameObject *life = new GameObject("life", new Vector2(-0.8 + (i *0.15), -0.8), 0.05);

		objectList->push_back(life);
	}*/

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------





	Shader();
	Texture();

	bool pressed = false;

	int random, fireInterval = 50, nextFireInterval = 0;

	while (!glfwWindowShouldClose(g_window)) {

		random = rand() % 9 + 0;
		nextFireInterval++;

		// wipe the drawing surface clear
		glClearColor(0.2f, 0.5f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glViewport(0, 0, g_gl_width, g_gl_height);

		// bind Texture
		glBindTexture(GL_TEXTURE_2D, texture);

		//
		// Note: this call is not necessary, but I like to do it anyway before any
		// time that I call glDrawArrays() so I never use the wrong shader programme
		glUseProgram(shader_programme);

		// Note: this call is not necessary, but I like to do it anyway before any
		// time that I call glDrawArrays() so I never use the wrong vertex data



		if (!objectList->empty())
		{
			for (std::list<GameObject*>::iterator it = objectList->begin(); it != objectList->end(); ++it)
			{
				GameObject *obj = *it;

				if (obj != nullptr)
				{
					if (Enemy* e = dynamic_cast<Enemy*>(obj))
					{
						//////e->SetTargetPosition(objectList->front()->position);
						//if (distance(objectList->begin(), it) == random + 1)
						//{
						//	if (nextFireInterval == fireInterval)
						//	{
						//		e->Fire(objectList->front()->position, -0.1);
						//		nextFireInterval = 0;
						//	}

						//}
					}

					obj->Update();
					obj->SetBuffer();
					Draw(obj->vao);
					//if (!objectList->empty())
					{
						//objectList->pop_front();
					}
				}


			}
			//PrintList();
		}


		// update other events like input handling
		glfwPollEvents();
		if (GLFW_PRESS == glfwGetKey(g_window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(g_window, 1);
		}
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(g_window);
	}

	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}
