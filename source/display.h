#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// @TODO: I only need 1 display, should I make this static?
struct Display {
  int initialised;
  GLFWwindow *window;
  int width;
  int height;
  void (*render)(void);
};

int initDisplay(Display *display);

int showDisplay(Display *display);
