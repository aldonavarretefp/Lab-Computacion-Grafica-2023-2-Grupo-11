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
		//0.5f,  0.5f, 0.0f, 1.0f,0.0f,0.0f,  // A
		//0.5f, -0.5f, 0.0f, 0.0f,1.0f,0.0f,  // B
		//-0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f,  // C
		//-0.5f,  0.5f, 0.0f,0.0f,1.0f,1.0f, //  D
		-0.5f,  0.7f, 0.0f,0.0f,1.0f,1.0f, //  A
		-0.7f,  0.4f, 0.0f,0.0f,1.0f,1.0f, //  A1
		-0.3f,  0.4f, 0.0f,0.0f,1.0f,1.0f, //  A2
		-0.5f,  0.4f, 0.0f,0.0f,1.0f,1.0f, //  A3
	
	};
	unsigned int indices[] = {  // note that we start from 0!
		0,1,3, // Triangle shade
		0,3,2, // Triangle line
		0,1,3,
		1,2,3
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
	    
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); // Tome 6 elementos y empieze en 3
		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); 
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat))); 
		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(6 * sizeof(GLfloat))); 
		
		// Triangulo
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat))); 
		glDrawElements(GL_LINES, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); 
		
		// Rect

		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)(0 * sizeof(GLfloat)));
		//glDrawElements(GL_LINES, 3, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat))); 

		// Trap

		// Hex

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