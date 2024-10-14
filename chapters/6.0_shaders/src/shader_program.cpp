#include "shader_program.hpp"

ShaderProgram::ShaderProgram(std::vector<ShaderUnit>&& shaderUnits)
  : shaders(std::move(shaderUnits))
{
  GLuint shaderProgram = glCreateProgram();
  for (const ShaderUnit& s : this->shaders) {
    glAttachShader(shaderProgram, s.getShader());
  }
  glLinkProgram(shaderProgram);
  check_status_program(
    shaderProgram, GL_LINK_STATUS, "ERROR::SHADERPROGRAM::LINK_FAILED\n");
  this->shaderProgram = shaderProgram;
}

ShaderProgram::~ShaderProgram()
{
  if (this->shaderProgram) {
    glDeleteShader(this->shaderProgram);
  }
}

GLuint
ShaderProgram::getShaderProgram() const
{
  return this->shaderProgram;
}

ShaderProgram::ShaderProgram(ShaderProgram&& other)
{
  this->shaderProgram = other.shaderProgram;
  this->shaders = std::move(other.shaders);
  other.shaderProgram = 0;
}
