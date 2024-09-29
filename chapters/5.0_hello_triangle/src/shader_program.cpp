#include "shader_program.hpp"

ShaderProgram::ShaderProgram(std::vector<ShaderUnit> &&shaderUnits) : shaders(shaderUnits) {
	GLuint shaderProgram = glCreateProgram();
	for(ShaderUnit s : this->shaders) {
		glAttachShader(shaderProgram, s.getShader());
	}
	glLinkProgram(shaderProgram);
	check_status(shaderProgram, GL_LINK_STATUS, "ERROR::SHADERPROGRAM::LINK_FAILED\n");
	this->shaderProgram = shaderProgram;
}

ShaderProgram::~ShaderProgram() {
	glDeleteShader(this->shaderProgram);
}

GLuint ShaderProgram::getShaderProgram() {
	return this->shaderProgram;
}
