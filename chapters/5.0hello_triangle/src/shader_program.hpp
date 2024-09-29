#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP
// Just standard C++ libraries
#include <vector>
// OpenGL specifics
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader_unit.hpp"

class ShaderProgram {
	public:
		// Take over the vector of shaders for this program
		ShaderProgram(std::vector<ShaderUnit> &&shaderUnits);
		~ShaderProgram();
		GLuint getShaderProgram();
	private:
		GLuint shaderProgram;
		std::vector<ShaderUnit> shaders;

};
#endif
