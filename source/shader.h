#include <GLFW/glfw3.h>

#ifndef _SHADERH_
#define _SHADERH_

struct Shader {
  unsigned int id;
  unsigned int fragment;
  unsigned int vertex;
};

Shader createShader(const char * vertexFileName, const char * fragmentFileName);

void deleteShader(Shader shader);
void useShader(Shader shader);

#endif

