#include <stdio.h>
#include <GLFW/glfw3.h>
#include "display.h"
#include "config.h"

int initDisplay(Display *display) {
  display->initialised = glfwInit();

  if (!display->initialised) {
    printf("init failed");
    return 1;
  }

  display->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, 0, 0);

  if (!display->window) {
    printf("window failed");
    return 1;
  }

  glfwGetFramebufferSize(display->window, &display->width, &display->height);

  glfwMakeContextCurrent(display->window);

  glViewport(0, 0, display->width, display->height);

  return 0;
}

void showDisplay(Display *display) {
  while (!glfwWindowShouldClose(display->window)) {
    glfwPollEvents();

    if (display->render) {
      display->render();
    }

    glfwSwapBuffers(display->window);
  }
}
