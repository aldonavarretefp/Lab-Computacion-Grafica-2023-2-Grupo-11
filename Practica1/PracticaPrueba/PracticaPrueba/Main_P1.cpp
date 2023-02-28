#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificación de errores de creacion  ventana
	if (window== NULL) 
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
		//X     Y     Z     R     G    B
		-0.5f,  0.9f, 0.0f, 0.588f, 0.266f, 0.913f, //  A
		-0.9f,  0.2f, 0.0f, 0.588f, 0.266f, 0.913f, //  A1
		-0.1f,  0.2f, 0.0f, 0.588f, 0.266f, 0.913f, //  A2
		-0.5f,  0.2f, 0.0f, 0.588f, 0.266f, 0.913f, //  A3
		 0.4f,  -0.2f, 0.0f,0.196f, 0.1f, 0.980f, //  B
		 0.6f,  -0.2f, 0.0f,0.196f, 0.1f, 0.980f, //  B1
		 0.9f,  -0.8f, 0.0f,0.196f, 0.1f, 0.980f, //  B2
		 0.1f,  -0.8f, 0.0f,0.196f, 0.1f, 0.980f, //  B3
		-0.2f,  -0.2f, 0.0f,0.127f, 0.811f, 1.0f, //  C
		-0.2f,  -0.8f, 0.0f,0.127f, 0.811f, 1.0f, //  C1
		-0.8f,  -0.8f, 0.0f,0.127f, 0.811f, 1.0f, //  C2
		-0.8f,  -0.2f, 0.0f,0.127f, 0.811f, 1.0f, //  C3
		0.5f,  0.9f, 0.0f,  1.0f, 0.2382f, 0.198f, //  D
		0.2f,  0.6f, 0.0f,  1.0f, 0.2382f, 0.198f, //  D1
		0.3f,  0.2f, 0.0f,  1.0f, 0.2382f, 0.198f, //  D2
		0.7f,  0.2f, 0.0f,  1.0f, 0.2382f, 0.198f, //  D3
		0.8f,  0.6f, 0.0f,  1.0f, 0.2382f, 0.198f, //  D4
	
	};
	unsigned int indices[] = {  // note that we start from 0!
		0,1,3, // Triangle shade
		0,3,2, // Triangle line

		5,6,7, // Trap shade
		4,5,7,  // Trap line

		9,10,11, // Rect shade
		8,9,11, // Rect line

		12,13,15,  // Hex shade 1
		12,15,16, // Hex shade 2
		13,14,15,     // Hex line
	};

	GLuint VBO, VAO,EBO; // Input vertex necesito crear los buffers.
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
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
		//glDrawArrays(GL_POINTS, 1, 1); // Unicamente trabaja con vertices y con la informacion contigua.
		//glDrawArrays(GL_POINTS, 3, 1); // Unicamente trabaja con vertices y con la informacion contigua. 
		
		// Triangulo
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat))); 
		glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); 
		
		// Trap
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(6 * sizeof(GLfloat))); 
		glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (GLvoid*)(9 * sizeof(GLfloat))); 
		
		// Rect

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(12 * sizeof(GLfloat)));
		glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (GLvoid*)(15 * sizeof(GLfloat))); 

		// Hex
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(18 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(21 * sizeof(GLfloat))); 
		glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (GLvoid*)(24 * sizeof(GLfloat))); 

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