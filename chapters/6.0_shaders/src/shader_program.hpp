#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP
// Just standard C++ libraries
#include <vector>
// Glad before OpenGL
#include <glad.h>
// OpenGL specifics
#include <GLFW/glfw3.h>

#include "shader_unit.hpp"

class ShaderProgram
{
public:
  // Take over the vector of shaders for this program
  ShaderProgram(std::vector<ShaderUnit>&& shaderUnits);
  ShaderProgram(ShaderProgram&&);
  ~ShaderProgram();
  GLuint getShaderProgram() const;

private:
  GLuint shaderProgram;
  std::vector<ShaderUnit> shaders;
};
#endif
