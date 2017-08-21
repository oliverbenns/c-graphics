#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Camera {
  glm::vec3 position;
  glm::vec3 target;
};

Camera createCamera();
