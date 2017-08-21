#include "camera.h"

Camera createCamera() {
  Camera camera;
  camera.position = glm::vec3(0.0f, 0.0f, 3.0f);
  camera.target = glm::vec3(0.0f, 0.0f, 0.0f);

  return camera;
}

glm::vec3 getCameraDirection(Camera camera) {
  return glm::normalize(camera.position - camera.target);
}
