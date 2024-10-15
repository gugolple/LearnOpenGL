#ifndef TRIANGLE_EJC_HPP
#define TRIANGLE_EJC_HPP

#include "drawable.hpp"

class Triangle_ejc : public Drawable
{
public:
  Triangle_ejc();
  Triangle_ejc(Triangle_ejc&&);
  Triangle_ejc(const Triangle_ejc&) = delete;
  virtual ~Triangle_ejc();
  virtual void render();
  virtual const ShaderProgram& getShaderProgram();

private:
  unsigned int VBO, VAO;
};

#endif
