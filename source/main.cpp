#include <stdio.h>
#include <GLFW/glfw3.h>

char title[] = "C Graphics";
int width = 640;
int height = 480;

int main() {
  if (!glfwInit()) {
    printf("glfwinit failed");
    return 1;
  }

  GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);

  if (!window) {
    printf("window failed");
    return 1;
  }

  int screenWidth, screenHeight;
  glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

  glfwMakeContextCurrent(window);

  glViewport(0, 0, screenWidth, screenHeight);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  return 0;
}
