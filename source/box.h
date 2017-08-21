#include "shader.h"
#include "texture.h"

struct Box {
  Texture texture;
};

Box createBox();

void renderBox(Box box, Shader shader);
