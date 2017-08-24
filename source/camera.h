#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Camera {
  glm::vec3 direction;
  glm::vec3 position;
  float speed;
  glm::vec3 up; // Specify the world 'up' direction. https://stackoverflow.com/questions/21830340/understanding-glmlookat
};

Camera createCamera();

glm::mat4 getWorldToViewMatrix(Camera camera);

void setCameraDirection(Camera *camera, glm::vec3 target);

void moveCamera(Camera *camera, GLFWwindow *window, float deltaTime);
