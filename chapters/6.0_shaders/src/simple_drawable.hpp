#ifndef SIMPLE_DRAWABLE_HPP
#define SIMPLE_DRAWABLE_HPP

#include "shader_handler.hpp"

// Glad before OpenGL
#include <glad.h>
// OpenGL specifics
#include <GLFW/glfw3.h>

#define VERTICES_TYPE float
#define INDICES_TYPE unsigned int

class SimpleDrawable
{
public:
  SimpleDrawable(std::vector<VERTICES_TYPE>&& vertices,
                 std::vector<INDICES_TYPE>&& indices,
                 unsigned int numVerts,
                 ShaderProgram&& shaderProgram);
  ~SimpleDrawable();
  void render();
  const ShaderProgram& getShaderProgram();

private:
  ShaderProgram shaderProgram;
  unsigned int VBO;
  unsigned int VAO;

  const unsigned int numVerts;
  const std::vector<VERTICES_TYPE> vertices;
  // We start from 0 and blocks of 3 numbers, because we draw triangles
  const std::vector<INDICES_TYPE> indices;
};

#endif
