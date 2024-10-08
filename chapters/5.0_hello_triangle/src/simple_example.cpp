// Just standard C++ libraries
#include <assert.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
// OpenGL specifics
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader_handler.hpp"
#include "drawable.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void init() {
	// GLFW Initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void prepareWindow(GLFWwindow* window){
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);

	// After initialization of GLFW
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, 800, 600);
}



void draw_func(GLFWwindow* window) {
	// Set the understandings of the function 
	// This will be removed when compiling for release
	assert(window!=NULL);
	// Function code
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

Drawable createTraingle1() {
	// Triangle 1 -- Shader setup
	std::vector<ShaderUnit> shaders = std::vector<ShaderUnit>();
	shaders.emplace_back("vertex_shader.glsl",GL_VERTEX_SHADER);
	shaders.emplace_back("fragment_shader.glsl",GL_FRAGMENT_SHADER);
	ShaderProgram shaderProgram = ShaderProgram(std::move(shaders));
	// Triangle 1 construction
	std::vector<float> vertices = {
		-1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		-0.3f, 0.0f, 0.0f
	};
	std::vector<unsigned int> indices = {
		0,1,2
	};
	return Drawable(std::move(vertices), std::move(indices), std::move(shaderProgram));
};

Drawable createTraingle2() {
	// Triangle 2 -- Shader setup
	std::vector<ShaderUnit> shaders = std::vector<ShaderUnit>();
	shaders.emplace_back("vertex_shader.glsl",GL_VERTEX_SHADER);
	shaders.emplace_back("fragment_shader_green.glsl",GL_FRAGMENT_SHADER);
	ShaderProgram shaderProgram = ShaderProgram(std::move(shaders));
	// Triangle 2 construction
	std::vector<float> vertices = {
		1.0f, -1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.3f, 0.0f, 0.0f
	};
	std::vector<unsigned int> indices = {
		0,1,2
	};
	return Drawable(std::move(vertices), std::move(indices), std::move(shaderProgram));
};

int main()
{
	init();

	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	prepareWindow(window);

	// After this point GL is ready
	Drawable triangle1 = createTraingle1();
	Drawable triangle2 = createTraingle2();


	// Infinite loop preventing close
	while(!glfwWindowShouldClose(window))
	{
		// Process inputs
		processInput(window);

		// Draw
		draw_func(window);
		//Temporary until reworked into a class or other solution
		triangle1.render();
		triangle2.render();

		// Swap screens, double buffered
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	glfwTerminate();
	return 0;
}

