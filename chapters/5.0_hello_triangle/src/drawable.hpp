#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "shader_handler.hpp"

// OpenGL specifics
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define VERTICES_TYPE float
#define INDICES_TYPE unsigned int 

class Drawable {
	public:
		Drawable(std::vector<VERTICES_TYPE> &&vertices,
				std::vector<INDICES_TYPE> &&indices,
				ShaderProgram &&shaderProgram);
		~Drawable();
		void render();
	private:
		ShaderProgram shaderProgram;
		unsigned int EBO;
		unsigned int VBO;
		unsigned int VAO;

		const std::vector<VERTICES_TYPE> vertices;
		// We start from 0 and blocks of 3 numbers, because we draw triangles
		const std::vector<INDICES_TYPE> indices;
};

#endif
