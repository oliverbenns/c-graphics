#include <OpenGL/gl3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_system.h"
#include "shader.h"

Shader createShader(const char * fileName, GLenum shaderType) {
  Shader shader;
  shader.id = glCreateShader(shaderType);
  shader.type = shaderType;

  // Only 2 types of enums so this is ok.
  const char * extension = shader.type == GL_VERTEX_SHADER ? ".vert" : ".frag";

  FileLocation fileLocation;
  fileLocation.path = "shaders/";
  fileLocation.fileName = fileName;
  fileLocation.extension = extension;

  char * vertexShaderSource = readFileFl(fileLocation);

  // Compile and attach GLSL commands to shader object ID.
  glShaderSource(shader.id, 1, &vertexShaderSource, NULL);
  glCompileShader(shader.id);

  free(vertexShaderSource);

  return shader;
}
