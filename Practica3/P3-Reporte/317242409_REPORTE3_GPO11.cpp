#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define squirtleskin 140.0f/255.0f, 212.0f/255.0f, 226.0f/255.0f
#define squirtlechest 233.0f/255.0f, 220.0f/255.0f, 188.0f/255.0f
#define squirtlechestStripes 208.0f/255.0f, 193.0f/255.0f, 160.0f/255.0f
#define squirtleTongeExterior 195.0f/255.0f, 75.0f/255.0f, 136.0f/255.0f
#define squirtleTonge 243.0f/255.0f, 164.0f/255.0f, 209.0f/255.0f
#define squirtleShell 163.0f/255.0f, 136.0f/255.0f, 119.0f/255.0f
#define squirtleShellStripes 115.0f/255.0f, 103.0f/255.0f, 87.0f/255.0f
#define squirtleShellWhite 240.0f/255.0f, 240.0f/255.0f, 240.0f/255.0f
#define squirtleBlack 0.0f, 0.0f, 0.0f


// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 3", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shaders/core.vs", "Shaders/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		//Cubo 1
		-0.5f, -0.5f, 0.5f, squirtleskin,//Front
		0.5f, -0.5f, 0.5f,  squirtleskin,
		0.5f,  0.5f, 0.5f,  squirtleskin,
		0.5f,  0.5f, 0.5f,  squirtleskin,
		-0.5f,  0.5f, 0.5f, squirtleskin,
		-0.5f, -0.5f, 0.5f, squirtleskin,
		-0.5f, -0.5f,-0.5f, squirtleskin,//Back
		 0.5f, -0.5f,-0.5f, squirtleskin,
		 0.5f,  0.5f,-0.5f, squirtleskin,
		 0.5f,  0.5f,-0.5f, squirtleskin,
		-0.5f,  0.5f,-0.5f, squirtleskin,
		-0.5f, -0.5f,-0.5f, squirtleskin,
		 0.5f, -0.5f,  0.5f, squirtleskin,
		 0.5f, -0.5f, -0.5f, squirtleskin,
		 0.5f,  0.5f, -0.5f, squirtleskin,
		 0.5f,  0.5f, -0.5f, squirtleskin,
		 0.5f,  0.5f,  0.5f, squirtleskin,
		 0.5f,  -0.5f, 0.5f, squirtleskin,
		-0.5f,  0.5f,  0.5f, squirtleskin,
		-0.5f,  0.5f, -0.5f, squirtleskin,
		-0.5f, -0.5f, -0.5f, squirtleskin,
		-0.5f, -0.5f, -0.5f, squirtleskin,
		-0.5f, -0.5f,  0.5f, squirtleskin,
		-0.5f,  0.5f,  0.5f, squirtleskin,
		-0.5f, -0.5f, -0.5f, squirtleskin,
		0.5f, -0.5f, -0.5f,  squirtleskin,
		0.5f, -0.5f,  0.5f,  squirtleskin,
		0.5f, -0.5f,  0.5f,  squirtleskin,
		-0.5f, -0.5f,  0.5f, squirtleskin,
		-0.5f, -0.5f, -0.5f, squirtleskin,
		-0.5f,  0.5f, -0.5f, squirtleskin,
		0.5f,  0.5f, -0.5f,  squirtleskin,
		0.5f,  0.5f,  0.5f,  squirtleskin,
		0.5f,  0.5f,  0.5f,  squirtleskin,
		-0.5f,  0.5f,  0.5f, squirtleskin,
		-0.5f,  0.5f, -0.5f, squirtleskin,
		//Cubo 2
		-0.5f, -0.5f, 0.5f,	  squirtlechest,//Front
		0.5f, -0.5f, 0.5f,	  squirtlechest,
		0.5f,  0.5f, 0.5f,	  squirtlechest,
		0.5f,  0.5f, 0.5f,	  squirtlechest,
		-0.5f,  0.5f, 0.5f,	  squirtlechest,
		-0.5f, -0.5f, 0.5f,	  squirtlechest,
		-0.5f, -0.5f,-0.5f,	  squirtlechest,//Back
		 0.5f, -0.5f,-0.5f,	  squirtlechest,
		 0.5f,  0.5f,-0.5f,	  squirtlechest,
		 0.5f,  0.5f,-0.5f,	  squirtlechest,
		-0.5f,  0.5f,-0.5f,	  squirtlechest,
		-0.5f, -0.5f,-0.5f,	  squirtlechest,
		 0.5f, -0.5f,  0.5f,  squirtlechest,
		 0.5f, -0.5f, -0.5f,  squirtlechest,
		 0.5f,  0.5f, -0.5f,  squirtlechest,
		 0.5f,  0.5f, -0.5f,  squirtlechest,
		 0.5f,  0.5f,  0.5f,  squirtlechest,
		 0.5f,  -0.5f, 0.5f,  squirtlechest,
		-0.5f,  0.5f,  0.5f,  squirtlechest,
		-0.5f,  0.5f, -0.5f,  squirtlechest,
		-0.5f, -0.5f, -0.5f,  squirtlechest,
		-0.5f, -0.5f, -0.5f,  squirtlechest,
		-0.5f, -0.5f,  0.5f,  squirtlechest,
		-0.5f,  0.5f,  0.5f,  squirtlechest,
		-0.5f, -0.5f, -0.5f,  squirtlechest,
		0.5f, -0.5f, -0.5f,	  squirtlechest,
		0.5f, -0.5f,  0.5f,	  squirtlechest,
		0.5f, -0.5f,  0.5f,	  squirtlechest,
		-0.5f, -0.5f,  0.5f,  squirtlechest,
		-0.5f, -0.5f, -0.5f,  squirtlechest,
		-0.5f,  0.5f, -0.5f,  squirtlechest,
		0.5f,  0.5f, -0.5f,	  squirtlechest,
		0.5f,  0.5f,  0.5f,	  squirtlechest,
		0.5f,  0.5f,  0.5f,	  squirtlechest,
		-0.5f,  0.5f,  0.5f,  squirtlechest,
		-0.5f,  0.5f, -0.5f,  squirtlechest,
		//Cubo 3
		-0.5f, -0.5f, 0.5f,	  squirtlechestStripes,//Front
		0.5f, -0.5f, 0.5f,	  squirtlechestStripes,
		0.5f,  0.5f, 0.5f,	  squirtlechestStripes,
		0.5f,  0.5f, 0.5f,	  squirtlechestStripes,
		-0.5f,  0.5f, 0.5f,	  squirtlechestStripes,
		-0.5f, -0.5f, 0.5f,	  squirtlechestStripes,
		-0.5f, -0.5f,-0.5f,	  squirtlechestStripes,//Back
		 0.5f, -0.5f,-0.5f,	  squirtlechestStripes,
		 0.5f,  0.5f,-0.5f,	  squirtlechestStripes,
		 0.5f,  0.5f,-0.5f,	  squirtlechestStripes,
		-0.5f,  0.5f,-0.5f,	  squirtlechestStripes,
		-0.5f, -0.5f,-0.5f,	  squirtlechestStripes,
		 0.5f, -0.5f,  0.5f,  squirtlechestStripes,
		 0.5f, -0.5f, -0.5f,  squirtlechestStripes,
		 0.5f,  0.5f, -0.5f,  squirtlechestStripes,
		 0.5f,  0.5f, -0.5f,  squirtlechestStripes,
		 0.5f,  0.5f,  0.5f,  squirtlechestStripes,
		 0.5f,  -0.5f, 0.5f,  squirtlechestStripes,
		-0.5f,  0.5f,  0.5f,  squirtlechestStripes,
		-0.5f,  0.5f, -0.5f,  squirtlechestStripes,
		-0.5f, -0.5f, -0.5f,  squirtlechestStripes,
		-0.5f, -0.5f, -0.5f,  squirtlechestStripes,
		-0.5f, -0.5f,  0.5f,  squirtlechestStripes,
		-0.5f,  0.5f,  0.5f,  squirtlechestStripes,
		-0.5f, -0.5f, -0.5f,  squirtlechestStripes,
		0.5f, -0.5f, -0.5f,	  squirtlechestStripes,
		0.5f, -0.5f,  0.5f,	  squirtlechestStripes,
		0.5f, -0.5f,  0.5f,	  squirtlechestStripes,
		-0.5f, -0.5f,  0.5f,  squirtlechestStripes,
		-0.5f, -0.5f, -0.5f,  squirtlechestStripes,
		-0.5f,  0.5f, -0.5f,  squirtlechestStripes,
		0.5f,  0.5f, -0.5f,	  squirtlechestStripes,
		0.5f,  0.5f,  0.5f,	  squirtlechestStripes,
		0.5f,  0.5f,  0.5f,	  squirtlechestStripes,
		-0.5f,  0.5f,  0.5f,  squirtlechestStripes,
		-0.5f,  0.5f, -0.5f,  squirtlechestStripes,
		//Cubo 4
		-0.5f, -0.5f, 0.5f,	  squirtleShellWhite,//Front
		0.5f, -0.5f, 0.5f,	  squirtleShellWhite,
		0.5f,  0.5f, 0.5f,	  squirtleShellWhite,
		0.5f,  0.5f, 0.5f,	  squirtleShellWhite,
		-0.5f,  0.5f, 0.5f,	  squirtleShellWhite,
		-0.5f, -0.5f, 0.5f,	  squirtleShellWhite,
		-0.5f, -0.5f,-0.5f,	  squirtleShellWhite,//Back
		 0.5f, -0.5f,-0.5f,	  squirtleShellWhite,
		 0.5f,  0.5f,-0.5f,	  squirtleShellWhite,
		 0.5f,  0.5f,-0.5f,	  squirtleShellWhite,
		-0.5f,  0.5f,-0.5f,	  squirtleShellWhite,
		-0.5f, -0.5f,-0.5f,	  squirtleShellWhite,
		 0.5f, -0.5f,  0.5f,  squirtleShellWhite,
		 0.5f, -0.5f, -0.5f,  squirtleShellWhite,
		 0.5f,  0.5f, -0.5f,  squirtleShellWhite,
		 0.5f,  0.5f, -0.5f,  squirtleShellWhite,
		 0.5f,  0.5f,  0.5f,  squirtleShellWhite,
		 0.5f,  -0.5f, 0.5f,  squirtleShellWhite,
		-0.5f,  0.5f,  0.5f,  squirtleShellWhite,
		-0.5f,  0.5f, -0.5f,  squirtleShellWhite,
		-0.5f, -0.5f, -0.5f,  squirtleShellWhite,
		-0.5f, -0.5f, -0.5f,  squirtleShellWhite,
		-0.5f, -0.5f,  0.5f,  squirtleShellWhite,
		-0.5f,  0.5f,  0.5f,  squirtleShellWhite,
		-0.5f, -0.5f, -0.5f,  squirtleShellWhite,
		0.5f, -0.5f, -0.5f,	  squirtleShellWhite,
		0.5f, -0.5f,  0.5f,	  squirtleShellWhite,
		0.5f, -0.5f,  0.5f,	  squirtleShellWhite,
		-0.5f, -0.5f,  0.5f,  squirtleShellWhite,
		-0.5f, -0.5f, -0.5f,  squirtleShellWhite,
		-0.5f,  0.5f, -0.5f,  squirtleShellWhite,
		0.5f,  0.5f, -0.5f,	  squirtleShellWhite,
		0.5f,  0.5f,  0.5f,	  squirtleShellWhite,
		0.5f,  0.5f,  0.5f,	  squirtleShellWhite,
		-0.5f,  0.5f,  0.5f,  squirtleShellWhite,
		-0.5f,  0.5f, -0.5f,  squirtleShellWhite,

		//Cubo 5
		-0.5f, -0.5f, 0.5f, squirtleShell,//Front
		0.5f, -0.5f, 0.5f,  squirtleShell,
		0.5f, 0.5f, 0.5f,   squirtleShell,
		0.5f, 0.5f, 0.5f,   squirtleShell,
		-0.5f, 0.5f, 0.5f,  squirtleShell,
		-0.5f, -0.5f, 0.5f, squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,//Back
		0.5f, -0.5f, -0.5f, squirtleShell,
		0.5f, 0.5f, -0.5f,  squirtleShell,
		0.5f, 0.5f, -0.5f,  squirtleShell,
		-0.5f, 0.5f, -0.5f, squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,
		0.5f, -0.5f, 0.5f,  squirtleShell,
		0.5f, -0.5f, -0.5f, squirtleShell,
		0.5f, 0.5f, -0.5f,  squirtleShell,
		0.5f, 0.5f, -0.5f,  squirtleShell,
		0.5f, 0.5f, 0.5f,   squirtleShell,
		0.5f, -0.5f, 0.5f,  squirtleShell,
		-0.5f, 0.5f, 0.5f,  squirtleShell,
		-0.5f, 0.5f, -0.5f, squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,
		-0.5f, -0.5f, 0.5f, squirtleShell,
		-0.5f, 0.5f, 0.5f,  squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,
		0.5f, -0.5f, -0.5f, squirtleShell,
		0.5f, -0.5f, 0.5f,  squirtleShell,
		0.5f, -0.5f, 0.5f,  squirtleShell,
		-0.5f, -0.5f, 0.5f, squirtleShell,
		-0.5f, -0.5f, -0.5f,squirtleShell,
		-0.5f, 0.5f, -0.5f, squirtleShell,
		0.5f, 0.5f, -0.5f,  squirtleShell,
		0.5f, 0.5f, 0.5f,   squirtleShell,
		0.5f, 0.5f, 0.5f,   squirtleShell,
		-0.5f, 0.5f, 0.5f,  squirtleShell,
		-0.5f, 0.5f, -0.5f, squirtleShell,
	
		//Cubo 6
		-0.5f, -0.5f, 0.5f, squirtleShellStripes,//Front
		0.5f, -0.5f, 0.5f,  squirtleShellStripes,
		0.5f, 0.5f, 0.5f,   squirtleShellStripes,
		0.5f, 0.5f, 0.5f,   squirtleShellStripes,
		-0.5f, 0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, -0.5f, 0.5f, squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,//Back
		0.5f, -0.5f, -0.5f, squirtleShellStripes,
		0.5f, 0.5f, -0.5f,  squirtleShellStripes,
		0.5f, 0.5f, -0.5f,  squirtleShellStripes,
		-0.5f, 0.5f, -0.5f, squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,
		0.5f, -0.5f, 0.5f,  squirtleShellStripes,
		0.5f, -0.5f, -0.5f, squirtleShellStripes,
		0.5f, 0.5f, -0.5f,  squirtleShellStripes,
		0.5f, 0.5f, -0.5f,  squirtleShellStripes,
		0.5f, 0.5f, 0.5f,   squirtleShellStripes,
		0.5f, -0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, 0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, 0.5f, -0.5f, squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,
		-0.5f, -0.5f, 0.5f, squirtleShellStripes,
		-0.5f, 0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,
		0.5f, -0.5f, -0.5f, squirtleShellStripes,
		0.5f, -0.5f, 0.5f,  squirtleShellStripes,
		0.5f, -0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, -0.5f, 0.5f, squirtleShellStripes,
		-0.5f, -0.5f, -0.5f,squirtleShellStripes,
		-0.5f, 0.5f, -0.5f, squirtleShellStripes,
		0.5f, 0.5f, -0.5f,  squirtleShellStripes,
		0.5f, 0.5f, 0.5f,   squirtleShellStripes,
		0.5f, 0.5f, 0.5f,   squirtleShellStripes,
		-0.5f, 0.5f, 0.5f,  squirtleShellStripes,
		-0.5f, 0.5f, -0.5f, squirtleShellStripes,

		//Cubo 7
		-0.5f, -0.5f, 0.5f,	  squirtleTongeExterior,//Front
		0.5f, -0.5f, 0.5f,	  squirtleTongeExterior,
		0.5f,  0.5f, 0.5f,	  squirtleTongeExterior,
		0.5f,  0.5f, 0.5f,	  squirtleTongeExterior,
		-0.5f,  0.5f, 0.5f,	  squirtleTongeExterior,
		-0.5f, -0.5f, 0.5f,	  squirtleTongeExterior,
		-0.5f, -0.5f,-0.5f,	  squirtleTongeExterior,//Back
		 0.5f, -0.5f,-0.5f,	  squirtleTongeExterior,
		 0.5f,  0.5f,-0.5f,	  squirtleTongeExterior,
		 0.5f,  0.5f,-0.5f,	  squirtleTongeExterior,
		-0.5f,  0.5f,-0.5f,	  squirtleTongeExterior,
		-0.5f, -0.5f,-0.5f,	  squirtleTongeExterior,
		 0.5f, -0.5f,  0.5f,  squirtleTongeExterior,
		 0.5f, -0.5f, -0.5f,  squirtleTongeExterior,
		 0.5f,  0.5f, -0.5f,  squirtleTongeExterior,
		 0.5f,  0.5f, -0.5f,  squirtleTongeExterior,
		 0.5f,  0.5f,  0.5f,  squirtleTongeExterior,
		 0.5f,  -0.5f, 0.5f,  squirtleTongeExterior,
		-0.5f,  0.5f,  0.5f,  squirtleTongeExterior,
		-0.5f,  0.5f, -0.5f,  squirtleTongeExterior,
		-0.5f, -0.5f, -0.5f,  squirtleTongeExterior,
		-0.5f, -0.5f, -0.5f,  squirtleTongeExterior,
		-0.5f, -0.5f,  0.5f,  squirtleTongeExterior,
		-0.5f,  0.5f,  0.5f,  squirtleTongeExterior,
		-0.5f, -0.5f, -0.5f,  squirtleTongeExterior,
		0.5f, -0.5f, -0.5f,	  squirtleTongeExterior,
		0.5f, -0.5f,  0.5f,	  squirtleTongeExterior,
		0.5f, -0.5f,  0.5f,	  squirtleTongeExterior,
		-0.5f, -0.5f,  0.5f,  squirtleTongeExterior,
		-0.5f, -0.5f, -0.5f,  squirtleTongeExterior,
		-0.5f,  0.5f, -0.5f,  squirtleTongeExterior,
		0.5f,  0.5f, -0.5f,	  squirtleTongeExterior,
		0.5f,  0.5f,  0.5f,	  squirtleTongeExterior,
		0.5f,  0.5f,  0.5f,	  squirtleTongeExterior,
		-0.5f,  0.5f,  0.5f,  squirtleTongeExterior,
		-0.5f,  0.5f, -0.5f,  squirtleTongeExterior,
		//Cubo 7
		-0.5f, -0.5f, 0.5f,	  squirtleTonge,//Front
		0.5f, -0.5f, 0.5f,	  squirtleTonge,
		0.5f,  0.5f, 0.5f,	  squirtleTonge,
		0.5f,  0.5f, 0.5f,	  squirtleTonge,
		-0.5f,  0.5f, 0.5f,	  squirtleTonge,
		-0.5f, -0.5f, 0.5f,	  squirtleTonge,
		-0.5f, -0.5f,-0.5f,	  squirtleTonge,//Back
		 0.5f, -0.5f,-0.5f,	  squirtleTonge,
		 0.5f,  0.5f,-0.5f,	  squirtleTonge,
		 0.5f,  0.5f,-0.5f,	  squirtleTonge,
		-0.5f,  0.5f,-0.5f,	  squirtleTonge,
		-0.5f, -0.5f,-0.5f,	  squirtleTonge,
		 0.5f, -0.5f,  0.5f,  squirtleTonge,
		 0.5f, -0.5f, -0.5f,  squirtleTonge,
		 0.5f,  0.5f, -0.5f,  squirtleTonge,
		 0.5f,  0.5f, -0.5f,  squirtleTonge,
		 0.5f,  0.5f,  0.5f,  squirtleTonge,
		 0.5f,  -0.5f, 0.5f,  squirtleTonge,
		-0.5f,  0.5f,  0.5f,  squirtleTonge,
		-0.5f,  0.5f, -0.5f,  squirtleTonge,
		-0.5f, -0.5f, -0.5f,  squirtleTonge,
		-0.5f, -0.5f, -0.5f,  squirtleTonge,
		-0.5f, -0.5f,  0.5f,  squirtleTonge,
		-0.5f,  0.5f,  0.5f,  squirtleTonge,
		-0.5f, -0.5f, -0.5f,  squirtleTonge,
		0.5f, -0.5f, -0.5f,	  squirtleTonge,
		0.5f, -0.5f,  0.5f,	  squirtleTonge,
		0.5f, -0.5f,  0.5f,	  squirtleTonge,
		-0.5f, -0.5f,  0.5f,  squirtleTonge,
		-0.5f, -0.5f, -0.5f,  squirtleTonge,
		-0.5f,  0.5f, -0.5f,  squirtleTonge,
		0.5f,  0.5f, -0.5f,	  squirtleTonge,
		0.5f,  0.5f,  0.5f,	  squirtleTonge,
		0.5f,  0.5f,  0.5f,	  squirtleTonge,
		-0.5f,  0.5f,  0.5f,  squirtleTonge,
		-0.5f,  0.5f, -0.5f,  squirtleTonge,

		//Cubo 7
		-0.5f, -0.5f, 0.5f, squirtleBlack,//Front
		0.5f, -0.5f, 0.5f,  squirtleBlack,
		0.5f, 0.5f, 0.5f,   squirtleBlack,
		0.5f, 0.5f, 0.5f,   squirtleBlack,
		-0.5f, 0.5f, 0.5f,  squirtleBlack,
		-0.5f, -0.5f, 0.5f, squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,//Back
		0.5f, -0.5f, -0.5f, squirtleBlack,
		0.5f, 0.5f, -0.5f,  squirtleBlack,
		0.5f, 0.5f, -0.5f,  squirtleBlack,
		-0.5f, 0.5f, -0.5f, squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,
		0.5f, -0.5f, 0.5f,  squirtleBlack,
		0.5f, -0.5f, -0.5f, squirtleBlack,
		0.5f, 0.5f, -0.5f,  squirtleBlack,
		0.5f, 0.5f, -0.5f,  squirtleBlack,
		0.5f, 0.5f, 0.5f,   squirtleBlack,
		0.5f, -0.5f, 0.5f,  squirtleBlack,
		-0.5f, 0.5f, 0.5f,  squirtleBlack,
		-0.5f, 0.5f, -0.5f, squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,
		-0.5f, -0.5f, 0.5f, squirtleBlack,
		-0.5f, 0.5f, 0.5f,  squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,
		0.5f, -0.5f, -0.5f, squirtleBlack,
		0.5f, -0.5f, 0.5f,  squirtleBlack,
		0.5f, -0.5f, 0.5f,  squirtleBlack,
		-0.5f, -0.5f, 0.5f, squirtleBlack,
		-0.5f, -0.5f, -0.5f,squirtleBlack,
		-0.5f, 0.5f, -0.5f, squirtleBlack,
		0.5f, 0.5f, -0.5f,  squirtleBlack,
		0.5f, 0.5f, 0.5f,   squirtleBlack,
		0.5f, 0.5f, 0.5f,   squirtleBlack,
		-0.5f, 0.5f, 0.5f,  squirtleBlack,
		-0.5f, 0.5f, -0.5f, squirtleBlack,

	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		// Se escuchan los eventos en el window
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	

		glBindVertexArray(VAO);

		// Cuerpo
		model = glm::scale(model, glm::vec3(1.0f, 1.3f, 0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 36, 72);

		// Cuerpo stripes
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.4f, 0.0f));
		model = glm::scale(model, glm::vec3(1.01f, 0.08f, 0.801f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 109);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, -0.1f, 0.0f));
		model = glm::scale(model, glm::vec3(1.01f, 0.08f, 0.801f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 109);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, -0.4f, 0.0f));
		model = glm::scale(model, glm::vec3(0.41f, 0.08f, 0.801f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 109);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.15f, 0.0f));
		model = glm::scale(model, glm::vec3(0.08f, 1.1f, 0.801f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 72, 109);
		
		// Shell white
		model = glm::mat4(1);
		model = glm::scale(model, glm::vec3(1.1f, 1.2f, 0.2f));
		model = glm::translate(model, glm::vec3(0.0f, -0.03f, -2.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 145);
		
		//Shell
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, -0.03f, -0.75f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 0.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 182);
		//Shell Stripes
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.2f, -0.75f));
		model = glm::scale(model, glm::vec3(1.01f, 0.101f, 0.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, -0.2f, -0.75f));
		model = glm::scale(model, glm::vec3(1.01f, 0.101f, 0.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 180, 216);

		// Cabeza
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 1.1f, 0.0f));
		model = glm::scale(model, glm::vec3(1.1f, 1.1f, 1.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// Cabeza - mandibula
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.75f, 0.09f));
		model = glm::scale(model, glm::vec3(1.1f, 0.45f, 1.2f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// Cabeza - tongeExterior
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.75f, 0.25f));
		model = glm::scale(model, glm::vec3(0.9f, 0.20f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 216, 243);

		// Cabeza - tonge
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, 0.75f, 0.251f));
		model = glm::scale(model, glm::vec3(0.7f, 0.10f, 0.901f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 243, 279);

		// Cabeza - ojo derecho
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.30f, 1.1f, 0.55f));
		model = glm::scale(model, glm::vec3(0.3f, 0.45f, 0.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 145);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.25f, 1.11f, 0.55f));
		model = glm::scale(model, glm::vec3(0.2f, 0.35f, 0.102f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 288, 324);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.23f, 1.19f, 0.56f));
		model = glm::scale(model, glm::vec3(0.09f, 0.09f, 0.09f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 145);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.248f, 1.0f, 0.58f));
		model = glm::scale(model, glm::vec3(0.2f, 0.09f, 0.05f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 182);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.245f, 1.04f, 0.585f));
		model = glm::scale(model, glm::vec3(0.07f, 0.07f, 0.07f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 288, 324);



		// Cabeza - ojo izquierdo
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.25f, 1.1f, 0.55f));
		model = glm::scale(model, glm::vec3(0.3f, 0.45f, 0.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 145);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.21f, 1.11f, 0.55f));
		model = glm::scale(model, glm::vec3(0.2f, 0.35f, 0.102f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 288, 324);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.21f, 1.19f, 0.56f));
		model = glm::scale(model, glm::vec3(0.09f, 0.09f, 0.09f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 108, 145);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.21f, 1.0f, 0.58f));
		model = glm::scale(model, glm::vec3(0.2f, 0.09f, 0.05f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 144, 182);

		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.205f, 1.04f, 0.585f));
		model = glm::scale(model, glm::vec3(0.07f, 0.07f, 0.07f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 288, 324);

		// Cola
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.0f, -0.3f, -0.75f));
		model = glm::scale(model, glm::vec3(0.4f, 0.9f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Pata derecha
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.35f, -0.6f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.6f, 0.35f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.35f, -0.9f, 0.03f));
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Pata izquierda
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.35f, -0.6f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.6f, 0.35f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.35f, -0.9f, 0.03f));
		model = glm::scale(model, glm::vec3(0.4f, 0.1f, 0.4f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Mano derecha
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(-0.55f, 0.2f, 0.2f));
		model = glm::scale(model, glm::vec3(0.4f, 0.35f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Mano izquierda
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(0.55f, 0.2f, 0.2f));
		model = glm::scale(model, glm::vec3(0.4f, 0.35f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		 movY += 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		 movY -= 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.001f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.01f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.01f;
 }


