#include "simple_drawable.hpp"
#include "math.h"

SimpleDrawable::SimpleDrawable(std::vector<float>&& vertices,
                               std::vector<unsigned int>&& indices,
                               unsigned int numVerts,
                               ShaderProgram&& shaderProgram)
  : vertices(vertices)
  , indices(indices)
  , shaderProgram(std::move(shaderProgram))
  , numVerts(numVerts)
{
  assert(indices.size() % 3 == 0);
  glGenVertexArrays(1, &this->VAO);
  glGenBuffers(1, &this->VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(this->VAO);

  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(VERTICES_TYPE) * this->vertices.size(),
               this->vertices.data(),
               GL_STATIC_DRAW);

  glVertexAttribPointer(0,
                        this->numVerts,
                        GL_FLOAT,
                        GL_FALSE,
                        this->numVerts * sizeof(float),
                        (void*)0);
  glEnableVertexAttribArray(0);

  // You can unbind the this->VAO afterwards so other this->VAO calls won't
  // accidentally modify this this->VAO, but this rarely happens. Modifying
  // other this->VAOs requires a call to glBindVertexArray anyways so we
  // generally don't unbind this->VAOs (nor this->VBOs) when it's not directly
  // necessary. glBindVertexArray(0);

  // bind the this->VAO (it was already bound, but just to demonstrate): seeing
  // as we only have a single this->VAO we can just bind it beforehand before
  // rendering the respective triangle; this is another approach.
  glBindVertexArray(this->VAO);
};

SimpleDrawable::~SimpleDrawable()
{
  // Release buffers
  glDeleteBuffers(1, &this->VBO);
  // Release vertex array
  GLuint arr[2];
  arr[0] = this->VAO;
  glDeleteVertexArrays(1, arr);
}

void
SimpleDrawable::render()
{
  glUseProgram(this->shaderProgram.getShaderProgram());
  glBindVertexArray(this->VAO);

  // render the triangle
  glDrawArrays(GL_TRIANGLES, 0, this->numVerts);
}

const ShaderProgram&
SimpleDrawable::getShaderProgram()
{
  return this->shaderProgram;
}
