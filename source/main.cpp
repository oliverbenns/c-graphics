#include <stdio.h>
#include <GLFW/glfw3.h>
#include "config.h"

int on = 0;

void newRender() {
  int value = on > 0 ? 255 : 0;
  glClearColor(value, value, value, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  on = on > 0 ? 0: 1;
}

int createDisplay() {
  int initialised = glfwInit();

  if (!initialised) {
    printf("glfwinit failed");
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, 0, 0);

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

    newRender();

    glfwSwapBuffers(window);
  }

  return 0;
}

int main() {
  createDisplay();
  return 0;
}
