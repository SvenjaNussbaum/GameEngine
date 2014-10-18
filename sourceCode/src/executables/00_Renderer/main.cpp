#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <vector>
#include <glm/glm.hpp>

#include "Renderer.h"
#include "Window.h"
#include "ShaderHandle.h"

//Example
GLfloat vertices[]  =
{ 
	0.5, -0.5,
	-0.5, -0.5, 
     0.5,  0.5,
	-0.5,  0.5,
};

std::vector<glm::vec3> m_vertices;

//variables for time measuring
double startTime = glfwGetTime();
double time = 0.0;
int i = 0;

/*
measure the time for a certain number of loops
*/
void timeMeasuring(int numberOfLoops){
	float deltaT = glfwGetTime() - startTime;
	if (i<numberOfLoops){
		time += deltaT;
		i++;
	}
	else{
		time = (int)(time * 100) / 100.0;
		std::cout << time << "s per "<<numberOfLoops<<" loops" << std::endl;
		time = 0;
		i = 0;
	}
	startTime = glfwGetTime();
}

/*
first example:

we set a window, 
initialize the renderer and load an object, 
set the shaderhandle & give him the path of the shaders 
and renderering the object in the gameloop
*/
int main() 
{
	m_vertices.push_back(glm::vec3(0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, -0.5, 0.0));
	m_vertices.push_back(glm::vec3(0.5, 0.5, 0.0));
	m_vertices.push_back(glm::vec3(-0.5, 0.5, 0.0));
    glfwInit();

	//our window
	Window* window = new Window(550,50,800,600, "Renderer Example");
	
    glewInit();
    


	//our renderer
	Renderer* renderer = new Renderer();

	
	ShaderHandle* shaderhandler = new ShaderHandle("\\00_Renderer\\minimal.vert", "\\00_Renderer\\minimal.frag");

	//Gameloop
	renderer->loadObject(&m_vertices);
    while( !glfwWindowShouldClose(window->getWindow()))
	{
		timeMeasuring(2000);
		renderer->render(window->getWindow());
    }

	window->close();
    return 0;
}