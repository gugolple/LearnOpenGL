#include "shader_program.hpp"

ShaderProgram::ShaderProgram(std::vector<ShaderUnit>&& shaderUnits)
{
  this->shaderProgram = glCreateProgram();
  for (const ShaderUnit& s : shaderUnits) {
    glAttachShader(this->shaderProgram, s.getShader());
  }
  this->constructShaderProgram();
}

ShaderProgram::ShaderProgram(std::initializer_list<ShaderUnit>&& shaderUnits)
{
  this->shaderProgram = glCreateProgram();
  for (const ShaderUnit& s : shaderUnits) {
    glAttachShader(this->shaderProgram, s.getShader());
  }
  this->constructShaderProgram();
}

void
ShaderProgram::constructShaderProgram()
{
  glLinkProgram(this->shaderProgram);
  check_status_program(
    shaderProgram, GL_LINK_STATUS, "ERROR::SHADERPROGRAM::LINK_FAILED\n");
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
  other.shaderProgram = 0;
}

void
ShaderProgram::userShaderProgram()
{
  glUseProgram(this->shaderProgram);
}
