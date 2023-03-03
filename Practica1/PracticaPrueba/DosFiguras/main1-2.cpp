#include<iostream>

//#define GLEW_STATIC
#define GREEN 

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 1000, HEIGHT = 1000;



int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1 - Dos Figuras", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);

	//Verificación de errores de creacion  ventana
	if (window == NULL)
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

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag"); // tambien se puede llamar .vertex


	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//X     Y     Z     R		G		B
		-0.9f,  0.2f, 0.0f, 0.86f,0.86f,0.84f, //  A
		-0.8f,  0.3f, 0.0f, 0.86f,0.86f,0.84f, //  A1
		-0.9f,  0.4f, 0.0f, 0.86f,0.86f,0.84f, //  A2

		-0.8f,  0.3f, 0.0f, 0.0f, 1.0f, 0.0f, //  A2
		-1.0f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //  A3
		-0.8f,  0.7f, 0.0f, 0.0f, 1.0f, 0.0f, //  A4

		-0.8f,  0.7f, 0.0f, 0.427f, 0.815f, 0.968f, //  A4
		-0.5f,  0.7f, 0.0f, 0.427f, 0.815f, 0.968f, //  A5
		-0.8f,  0.4f, 0.0f, 0.427f, 0.815f, 0.968f, //  A6
		
		-0.5f,  0.7f, 0.0f, 0.960f, 0.513f, 0.129f, //  A5
		-0.5f,  0.5f, 0.0f, 0.960f, 0.513f, 0.129f, //  A7
		-0.7f,  0.5f, 0.0f, 0.960f, 0.513f, 0.129f, //  A8

		-0.5f,  0.5f, 0.0f, 0.682f, 0.666f, 0.823f, //  A7
		-0.7f,  0.5f, 0.0f, 0.682f, 0.666f, 0.823f, //  A8
		-0.3f,  0.3f, 0.0f, 0.682f, 0.666f, 0.823f, //  A9

		-0.7f,  0.5f, 0.0f, 0.682f, 0.666f, 0.823f, //  A8
		-0.3f,  0.3f, 0.0f, 0.682f, 0.666f, 0.823f, //  A9
		-0.5f,  0.3f, 0.0f, 0.682f, 0.666f, 0.823f, //  A10
		
		-0.5f,  0.7f, 0.0f, 1.0f, 0.760f, 0.058f, //  A5
		-0.5f,  0.5f, 0.0f, 1.0f, 0.760f, 0.058f, //  A7
		-0.3f,  0.5f, 0.0f, 1.0f, 0.760f, 0.058f, //  A15
		-0.5f,  0.7f, 0.0f, 1.0f, 0.760f, 0.058f, //  A5
		-0.3f,  0.7f, 0.0f, 1.0f, 0.760f, 0.058f, //  A13
		-0.3f,  0.5f, 0.0f, 1.0f, 0.760f, 0.058f, //  A15
		
		-0.3f,  0.7f, 0.0f, 1.0f, 0.0f, 0.0f, //  A13
		-0.1f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //  A14
		-0.3f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //  A15


		0.57f,   -0.9f, 0.0f,  0.247f, 0.968f, 0.113f, //  B
		0.3f,   -0.9f, 0.0f,  0.247f, 0.968f, 0.113f, //  B1
		0.3f,   -0.6f, 0.0f,  0.247f, 0.968f, 0.113f, //  B2
		
		0.3f,   -0.6f, 0.0f,  0.427f, 0.815f, 0.968f, //  B2
		0.50f,  -0.34f, 0.0f, 0.427f, 0.815f, 0.968f, //  B3
		0.50f,  -0.83f, 0.0f, 0.427f, 0.815f, 0.968f, //  B4
		
		0.50f,  -0.34f, 0.0f,  0.960f, 0.513f, 0.129f, //  B3
		0.8f,   -0.6f, 0.0f,   0.960f, 0.513f, 0.129f, //  B5
		0.50f,   -0.6f, 0.0f,  0.960f, 0.513f, 0.129f, //  B6

		0.8f,   -0.6f, 0.0f,   0.811f, 0.819f, 0.823f, //  B5
		0.8f,   -0.7f, 0.0f,   0.811f, 0.819f, 0.823f, //  B8
		0.598f,  -0.6f, 0.0f,   0.811f, 0.819f, 0.823f, //  C

		0.50f,  -0.34f, 0.0f,  0.996f, 0.764f, 0.058f, //  B3
		0.66f,  -0.48f, 0.0f,  0.996f, 0.764f, 0.058f, //  B9
		0.66f,  -0.18f, 0.0f,  0.996f, 0.764f, 0.058f, //  B11

		0.66f,  -0.48f, 0.0f,  0.996f, 0.764f, 0.058f, //  B9
		0.82f,   -0.33f, 0.0f,  0.996f, 0.764f, 0.058f, //  B10
		0.66f,  -0.18f, 0.0f,  0.996f, 0.764f, 0.058f, //  B11

		0.66f,  -0.18f, 0.0f,  0.682f, 0.666f, 0.831f, //  B11
		0.57f,  0.1f, 0.0f,	   0.682f, 0.666f, 0.831f, //  B12
		0.66f,  0.0f, 0.0f,  0.682f, 0.666f, 0.831f, //  B13
		
		0.66f,  -0.18f, 0.0f,  0.682f, 0.666f, 0.831f, //  B11
		0.57f,  0.1f, 0.0f,    0.682f, 0.666f, 0.831f, //  B12
		0.57f,  -0.1f, 0.0f,  0.682f, 0.666f, 0.831f, //  B14
		
		//0.8f,   -0.6f, 0.0f,    0.996, 0.764, 0.058, //  B5
		//0.8f,   -0.33f, 0.0f,  0.466f, 0.082f, 0.898f, //  B10
		//0.57f,  -0.09f, 0.0f,  0.466f, 0.082f, 0.898f, //  B14
		0.82f,   -0.33f, 0.0f,  1.0f, 0.0f, 0.0f, //  B10
		0.95f,   -0.33f, 0.0f, 1.0f, 0.0f, 0.0f, //  B15
		0.95f,   -0.15f, 0.0f,  1.0f, 0.0f, 0.0f, //  B16
	};
	unsigned int indices[] = {  // note that we start from 0!
		// Figura A
		0,1,2,   
		3,4,5,   
		6,7,8,
		9,10,11,
		12,13,14,
		15,16,17,
		18,19,20,
		21,22,23,
		24,25,26,

		// Figura B
		27+0,27+1 ,27+2,
		27+3,27+4 ,27+5,
		27+6,27+7 ,27+8,
		27+9,27+10 ,27+11,
		27+12,27+13 ,27+14,
		27+15,27+16 ,27+17,
		27+18,27+19 ,27+20,
		27+21,27+22 ,27+23,
		27+24,27+25 ,27+26,
	};

	GLuint VBO, VAO, EBO; // Input vertex necesito crear los buffers.
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Desenlazamos de memoria el VAO
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aquí
		OurShader.Use(); // {
		glBindVertexArray(VAO);
		glPointSize(10);
		// Figura A
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(6 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(9 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(12 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(15 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(18 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(21 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(24 * sizeof(GLfloat)));

		// Figura B
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(27 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(30 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(33 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(36 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(39 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(42 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(45 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(48 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(51 * sizeof(GLfloat)));
		
		
		glBindVertexArray(0);// }

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}