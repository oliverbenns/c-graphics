#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "file_system.h"
#include "shader.h"

unsigned int loadShader(const char * fileName, GLenum type) {
  unsigned int id = glCreateShader(type);

  // Only 2 types of enums so this is ok.
  const char * extension = type == GL_VERTEX_SHADER ? ".vert" : ".frag";

  char * vertexShaderSource = readFileUrn("shaders/", fileName, extension);

  // Compile and attach GLSL commands to shader object ID.
  glShaderSource(id, 1, &vertexShaderSource, NULL);
  glCompileShader(id);

  free(vertexShaderSource);

  return id;
}

Shader createShader(const char * vertexFileName, const char * fragmentFileName) {
  Shader shader;

  shader.id = glCreateProgram();;
  shader.fragment = loadShader(fragmentFileName, GL_FRAGMENT_SHADER);
  shader.vertex = loadShader(vertexFileName, GL_VERTEX_SHADER);

  glAttachShader(shader.id, shader.vertex);
  glAttachShader(shader.id, shader.fragment);
  glLinkProgram(shader.id);

  return shader;
}

void useShader(Shader shader) {
  glUseProgram(shader.id);
}

void deleteShader(Shader shader) {
  glDeleteShader(shader.fragment);
  glDeleteShader(shader.vertex);
}

void setShaderParam(Shader shader, char const* name, glm::mat4 matrix) {
  int location = glGetUniformLocation(shader.id, name);
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
