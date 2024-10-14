#ifndef TRIANGLE1_HPP
#define TRIANGLE1_HPP

#include "drawable.hpp"

class Triangle1 : public Drawable
{
public:
  Triangle1();
  Triangle1(Triangle1&&);
  Triangle1(const Triangle1&) = delete;
  virtual ~Triangle1();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
