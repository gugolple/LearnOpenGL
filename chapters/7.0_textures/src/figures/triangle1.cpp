#include "triangle1.hpp"
#include <cmath>
#include <cstdio>

#define VERTICES_TYPE float
#define INDICES_TYPE unsigned int

// On Drawable we pass the shaders that we want for the program.
// Drawable is doing the managing of the ShaderProgram.
Triangle1::Triangle1()
  : Drawable({ ShaderUnit("vertex_shader.glsl", GL_VERTEX_SHADER),
               ShaderUnit("fragment_shader.glsl", GL_FRAGMENT_SHADER) })
  , image(std::move(*ImageLoader::loadImage("container.jpg")))
{
  float vertices[] = {
    // positions
    // colors
    // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };

  unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
  };
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(
    GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(
    1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  // texture coord attribute
  glVertexAttribPointer(
    2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);
};

Triangle1::~Triangle1()
{
  // Release buffers
  GLuint arr[2] = { this->VBO, this->EBO };
  glDeleteBuffers(2, arr);
  // Release vertex array
  arr[0] = this->VAO;
  glDeleteVertexArrays(1, arr);
}

void
Triangle1::render()
{
  this->image.activate();
  this->shaderProgram.userShaderProgram();
  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

const ShaderProgram&
Triangle1::getShaderProgram()
{
  return this->shaderProgram;
}
