#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP
// Just standard C++ libraries
#include <initializer_list>
#include <vector>
// Glad before OpenGL
#include <glad.h>
// OpenGL specifics
#include <GLFW/glfw3.h>

// CPP related
#include "shader_unit.hpp"

class ShaderProgram
{
public:
  // Take over the vector of shaders for this program
  ShaderProgram(std::vector<ShaderUnit>&& shaderUnits);
  ShaderProgram(std::initializer_list<ShaderUnit>&& shaderUnits);
  ShaderProgram(ShaderProgram&&);
  ~ShaderProgram();
  GLuint getShaderProgram() const;
  void userShaderProgram();

private:
  void constructShaderProgram();
  GLuint shaderProgram;
};
#endif
