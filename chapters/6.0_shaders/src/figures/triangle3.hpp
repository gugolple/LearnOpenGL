#ifndef TRIANGLE3_HPP
#define TRIANGLE3_HPP

#include "drawable.hpp"

class Triangle3 : public Drawable
{
public:
  Triangle3();
  Triangle3(Triangle3&&);
  Triangle3(const Triangle3&) = delete;
  virtual ~Triangle3();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
