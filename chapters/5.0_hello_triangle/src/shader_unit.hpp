#ifndef SHADER_UNIT_HPP
#define SHADER_UNIT_HPP

// Just standard C++ libraries
#include <assert.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
// OpenGL specifics
#include <glad/glad.h>
#include <GLFW/glfw3.h>


int check_status(unsigned int element, GLenum pname, const char* message);

class ShaderUnit {
	public:
		ShaderUnit(const char* filename, GLenum shaderType);
		~ShaderUnit();
		GLuint getShader();
		GLenum getShaderType();
	private:
		const GLuint shader;
		const GLenum shaderType; 
};

#endif
