#include <stdio.h>
#include <GLFW/glfw3.h>
#include "display.h"

// int on = 0;
float value = 0;
enum direction {FORWARD, REVERSE};
enum direction foo = FORWARD;

void render() {
  glClearColor(value, value, value, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  
  value+= foo == FORWARD ? 0.015 : -0.015;

  if (value < 0) {
    foo = FORWARD;
  }

  if (value > 1) {
    foo = REVERSE;
  }

}

int main() {
  Display display;

  initDisplay(&display);

  display.render = render;

  showDisplay(&display);

  return 0;
}
