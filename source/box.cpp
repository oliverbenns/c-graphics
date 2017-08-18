#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "box.h"

Box createBox() {
  Box box;
  box.texture = createTexture("box");
  box.texture2 = createTexture("smiley");

  return box;
}

void renderBox(Box box, Shader shader) {
  glm::mat4 transform;
  transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
  transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

  // get matrix's uniform location and set matrix
  unsigned int transformLoc = glGetUniformLocation(shader.id, "transform");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
}
