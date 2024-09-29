#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

int main()
{
	cout << "Hello World" << endl;
	// define the function’s prototype
	typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
	// find the function and assign it to a function pointer
	GL_GENBUFFERS glGenBuffers =
		(GL_GENBUFFERS)glfwGetProcAddress("glGenBuffers");
	// function can now be called as normal
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	return 0;
}

