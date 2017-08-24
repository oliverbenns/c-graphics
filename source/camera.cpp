#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glm/ext.hpp"
#include "camera.h"
#include <iostream>

Camera createCamera() {
  Camera camera;
  camera.position = glm::vec3(0.0f, 0.0f, 3.0f);
  camera.direction = glm::vec3(0.0f, 0.0f, -1.0f);
  camera.speed = 3.0f;
  camera.up = glm::vec3(0.0f, 1.0f, 0.0f);

  return camera;
}

void setCameraDirection(Camera *camera, glm::vec3 target) {
  camera->direction = glm::normalize(camera->position + target);
}

glm::mat4 getWorldToViewMatrix(Camera camera) {
  glm::vec3 center = camera.position + camera.direction;

  return glm::lookAt(camera.position, center, camera.up);
}

void moveCamera(Camera *camera, GLFWwindow *window, float deltaTime) {
  float speed = camera->speed * deltaTime;
  glm::vec3 velocity;

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    velocity += speed * camera->direction;
  }

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    velocity -= speed * camera->direction;
  }

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    velocity -= glm::normalize(glm::cross(camera->direction, camera->up)) * speed;
  }

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    velocity += glm::normalize(glm::cross(camera->direction, camera->up)) * speed;
  }

  camera->position += velocity;
}
