#include "triangle_ej3.hpp"

#define VERTICES_TYPE float
#define INDICES_TYPE unsigned int

// On Drawable we pass the shaders that we want for the program.
// Drawable is doing the managing of the ShaderProgram.
Triangle_ej3::Triangle_ej3()
  : Drawable({ ShaderUnit("vertex_shader_ej3.glsl", GL_VERTEX_SHADER),
               ShaderUnit("fragment_shader_ej3.glsl", GL_FRAGMENT_SHADER) })
{
  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
    0.5f,  -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    0.0f,  0.5f,  0.0f  // top
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
};

Triangle_ej3::~Triangle_ej3()
{
  // Release buffers
  GLuint arr[1] = { this->VBO };
  glDeleteBuffers(1, arr);
  // Release vertex array
  arr[0] = this->VAO;
  glDeleteVertexArrays(1, arr);
}

void
Triangle_ej3::render()
{
  this->shaderProgram.userShaderProgram();
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

const ShaderProgram&
Triangle_ej3::getShaderProgram()
{
  return this->shaderProgram;
}
