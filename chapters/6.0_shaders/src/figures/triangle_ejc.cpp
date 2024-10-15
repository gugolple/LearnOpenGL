#include "triangle_ejc.hpp"

#define VERTICES_TYPE float
#define INDICES_TYPE unsigned int

// On Drawable we pass the shaders that we want for the program.
// Drawable is doing the managing of the ShaderProgram.
Triangle_ejc::Triangle_ejc()
  : Drawable({ ShaderUnit("vertex_shader_ejc.glsl", GL_VERTEX_SHADER),
               ShaderUnit("fragment_shader_ejc.glsl", GL_FRAGMENT_SHADER) })
{
  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
    // positions
    // colors
    0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f  // top
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(
    1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
};

Triangle_ejc::~Triangle_ejc()
{
  // Release buffers
  GLuint arr[1] = { this->VBO };
  glDeleteBuffers(1, arr);
  // Release vertex array
  arr[0] = this->VAO;
  glDeleteVertexArrays(1, arr);
}

void
Triangle_ejc::render()
{
  this->shaderProgram.userShaderProgram();
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

const ShaderProgram&
Triangle_ejc::getShaderProgram()
{
  return this->shaderProgram;
}
