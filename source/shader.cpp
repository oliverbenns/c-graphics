#include <OpenGL/gl3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_system.h"
#include "shader.h"

unsigned int createShader(const char * fileName, GLenum shaderType) {
  unsigned int vertexShader = glCreateShader(shaderType);

  // Only 2 types of enums so this is ok.
  const char * extension = shaderType == GL_VERTEX_SHADER ? ".vert" : ".frag";

  // @TODO: Function overload this?
  char * uri = createUri("shaders/", fileName, extension);
  char * vertexShaderSource = readFile(uri);

  // Compile and attach GLSL commands to shader object ID.
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  free(uri);
  free(vertexShaderSource);

  return vertexShader;
}
