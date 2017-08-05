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

  // Tell GLFW what version of OpenGL we are running.
  // @TODO: We can probably get this from openGL somehow.
  // @TODO: What openGL am I actually running? Homebrew is @3.2.1 but XCode is importing from Apple default (4.1)
  // printf("OPEN GL VERSION: %s\n", glGetString(GL_VERSION));
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // This fixes OSX, see comments: https://learnopengl.com/#!Getting-started/Hello-Window

  display->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, 0, 0);

  if (!display->window) {
    printf("window failed");
    glfwTerminate();
    return 1;
  }

  // Make Window Context the main one on current thread.
  glfwMakeContextCurrent(display->window);

  // Tell OpenGL the size of the rendering Window. Which is the size of the Window.
  // It might be good to hardcode this based on WINDOW_WIDTH + WINDOW_HEIGHT for now. Would prevent glfwGetFramebufferSize call.
  glfwGetFramebufferSize(display->window, &display->width, &display->height);
  glViewport(0, 0, display->width, display->height);

  return 0;
}

int showDisplay(Display *display) {
  while (!glfwWindowShouldClose(display->window)) {
    glfwPollEvents();

    if (display->render) {
      display->render();
    }

    glfwSwapBuffers(display->window);
  }

  glfwTerminate();

  return 0;
}
