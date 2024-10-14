#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "shader_handler.hpp"

// Glad before OpenGL
#include <glad.h>
// OpenGL specifics
#include <GLFW/glfw3.h>

class Drawable
{
public:
  Drawable(ShaderProgram&&);
  Drawable(Drawable&&);
  Drawable(const Drawable&) = delete;
  virtual ~Drawable();
  virtual void render() = 0;
  const ShaderProgram& getShaderProgram();

protected:
  ShaderProgram shaderProgram;
};

#endif
