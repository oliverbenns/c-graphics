// @TODO
// Read the file contents into memory
// Decode the file to raw format required (RGB or RGBA)
// Create OpenGL texture object and give the raw image data to OpenGL
// Construct OpenGL primitive with appropriate texture coordinates and vertices positions.
// Bind the texture to appropriate texture unit and use a sampler object to use the texture data to produce final color.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_system.h"
#include "image.h"

char * decodeImage(const char * imageData);

char * loadImage(const char * fileName) {
  FileLocation fileLocation;
  fileLocation.path = "images/";
  fileLocation.fileName = fileName;
  fileLocation.extension = ".png";

  char * data = readFileFl(fileLocation);

  return data;
};

Image createImage(const char * fileName) {
  Image image;

  char * data = loadImage(fileName);

  char * decodedData = decodeImage(data);

  free(data);

  return image;
}
