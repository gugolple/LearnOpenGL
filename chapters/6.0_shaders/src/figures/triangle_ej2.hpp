#ifndef TRIANGLE_EJ2_HPP
#define TRIANGLE_EJ2_HPP

#include "drawable.hpp"

class Triangle_ej2 : public Drawable
{
public:
  Triangle_ej2();
  Triangle_ej2(Triangle_ej2&&);
  Triangle_ej2(const Triangle_ej2&) = delete;
  virtual ~Triangle_ej2();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
