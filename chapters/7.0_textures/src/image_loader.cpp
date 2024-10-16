#include "image_loader.hpp"

// Glad before OpenGL
#include <glad.h>
// OpenGL specifics
#include <GLFW/glfw3.h>

// Image loading
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::optional<ImageLoader>
ImageLoader::loadImage(const char* image_path)
{
  // Load image using library
  int width, height, nrChannels;
  unsigned char* data = stbi_load(image_path, &width, &height, &nrChannels, 0);
  if (data) {
    return std::make_optional<ImageLoader>(data, width, height, nrChannels);
  }
  return std::nullopt;
}

ImageLoader::ImageLoader(unsigned char* data,
                         int width,
                         int height,
                         int nrChannels)
  : width(width)
  , height(height)
  , nrChannels(nrChannels)
  , texture(0)
{
  // Create and bind texture
  glGenTextures(1, &this->texture);
  glBindTexture(GL_TEXTURE_2D, this->texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(
    GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
}

ImageLoader::ImageLoader(ImageLoader&& other)
{
  this->width = other.width;
  this->height = other.height;
  this->nrChannels = other.nrChannels;
  this->texture = other.texture;
  other.texture = 0;
}

ImageLoader::~ImageLoader()
{
  if (this->texture) {
  }
}

void
ImageLoader::activate()
{
  glBindTexture(GL_TEXTURE_2D, this->texture);
}
