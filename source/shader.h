#include <GLFW/glfw3.h>

struct Shader {
  unsigned int id;
  GLenum type;
};

Shader createShader(const char * fileName, GLenum shaderType);
