#ifndef TRIANGLE_EJ3_HPP
#define TRIANGLE_EJ3_HPP

#include "drawable.hpp"

class Triangle_ej3 : public Drawable
{
public:
  Triangle_ej3();
  Triangle_ej3(Triangle_ej3&&);
  Triangle_ej3(const Triangle_ej3&) = delete;
  virtual ~Triangle_ej3();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
