#include "drawable.hpp"

Drawable::Drawable(std::vector<float> &&vertices,
		std::vector<unsigned int> &&indices,
		ShaderProgram &&shaderProgram):
	vertices(vertices), indices(indices), shaderProgram(shaderProgram) {
	assert(indices.size()%3==0);
	// Initialize to known values to check correct initialization
	this->VBO = -1;
	this->EBO = -1;
	this->VAO = -1;

	// Create the buffer for VBO
	glGenBuffers(1, &this->VBO);
	assert(this->VBO != -1);
	glGenBuffers(1, &this->EBO);
	assert(this->EBO != -1);

	// Set buffers for the triangle
	// Pass the vertices to the GL
	// This is the preloading-setup phase
	glGenVertexArrays(1, &this->VAO);
	assert(this->VAO != -1);

	// 1. bind Vertex Array Object
	glBindVertexArray(this->VAO);
	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES_TYPE)*this->vertices.size(), this->vertices.data(),
			GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES_TYPE)*this->indices.size(), this->indices.data(),
			GL_STATIC_DRAW);
	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
			(void*)0);
	glEnableVertexAttribArray(0);
};

Drawable::~Drawable() {
	// Release buffers
	GLuint arr[2] = {this->VBO, this->EBO};
	glDeleteBuffers(2, arr);
	// Release vertex array
	arr[0] = this->VAO;
	glDeleteVertexArrays(1, arr);
}

void Drawable::render() {
	glUseProgram(this->shaderProgram.getShaderProgram());
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
