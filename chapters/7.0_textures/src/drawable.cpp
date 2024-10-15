#include "drawable.hpp"

Drawable::Drawable(ShaderProgram&& shaderProgram)
  : shaderProgram(std::move(shaderProgram))
{
}

Drawable::Drawable(Drawable&& other)
  : shaderProgram(std::move(other.shaderProgram))
{
}

Drawable::~Drawable() {}

const ShaderProgram&
Drawable::getShaderProgram()
{
  return this->shaderProgram;
}
