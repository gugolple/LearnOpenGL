#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP
#include <optional>

class ImageLoader
{
public:
  static std::optional<ImageLoader> loadImage(const char*);
  ImageLoader(unsigned char* data, int width, int height, int nrChannels);
  ImageLoader(const ImageLoader&) = delete;
  ImageLoader(ImageLoader&&);
  ~ImageLoader();
  void activate();

private:
  int width, height, nrChannels;
  unsigned int texture;
};

#endif
