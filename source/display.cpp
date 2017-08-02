#include <stdio.h>
#include <GLFW/glfw3.h>
#include "display.h"
#include "config.h"

int createDisplay(
  void (*render)(void)
) {
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

    render();

    glfwSwapBuffers(window);
  }

  return 0;
}
