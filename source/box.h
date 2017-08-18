#include "shader.h"
#include "texture.h"

struct Box {
  Texture texture;
  Texture texture2;
};

Box createBox();

void renderBox(Box box, Shader shader);
