#define STB_IMAGE_IMPLEMENTATION
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "stb_image.h"
#include "texture.h"

Texture createTexture(const char * fileName) {
  Texture texture;

  unsigned char * data = stbi_load("images/container.jpg", &texture.width, &texture.height, &texture.channelCount, 0);

  if (!data) {
    printf("Failed to load texture");
    return texture;
  }

  glGenTextures(1, &texture.id);
  glBindTexture(GL_TEXTURE_2D, texture.id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  return texture;
}
