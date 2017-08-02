#include <stdio.h>
#include <GLFW/glfw3.h>
#include "display.h"

int on = 0;

void render() {
  int value = on > 0 ? 255 : 0;
  glClearColor(value, value, value, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  on = on > 0 ? 0: 1;
}

int main() {
  createDisplay(render);
  return 0;
}
