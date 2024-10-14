#ifndef TRIANGLE2_HPP
#define TRIANGLE2_HPP

#include "drawable.hpp"

class Triangle2 : public Drawable
{
public:
  Triangle2();
  Triangle2(Triangle2&&);
  Triangle2(const Triangle2&) = delete;
  virtual ~Triangle2();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
