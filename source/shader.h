#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

void setShaderParam(Shader shader, char const* name, glm::mat4 matrix);

#endif

