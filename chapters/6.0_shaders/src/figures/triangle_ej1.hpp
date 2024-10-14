#ifndef TRIANGLE_EJ1_HPP
#define TRIANGLE_EJ1_HPP

#include "drawable.hpp"

class Triangle_ej1 : public Drawable
{
public:
  Triangle_ej1();
  Triangle_ej1(Triangle_ej1&&);
  Triangle_ej1(const Triangle_ej1&) = delete;
  virtual ~Triangle_ej1();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
