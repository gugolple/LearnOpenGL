#ifndef SHADER_UNIT_HPP
#define SHADER_UNIT_HPP

// Just standard C++ libraries
#include <assert.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
// OpenGL specifics
#include <glad.h>
#include <GLFW/glfw3.h>


int check_status_program(unsigned int element, GLenum pname, const char* message);
int check_status_shader(unsigned int element, GLenum pname, const char* message);

class ShaderUnit {
	public:
		ShaderUnit(const char* filename, GLenum shaderType);
		ShaderUnit(const ShaderUnit&) = delete;
		ShaderUnit(ShaderUnit&&);
		~ShaderUnit();
		GLuint getShader() const;
		GLenum getShaderType() const;
	private:
		GLuint shader;
		const GLenum shaderType; 
};

#endif
