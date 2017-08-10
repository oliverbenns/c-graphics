#include "texture.h"
#include "box.h"

Box createBox() {
  Box box;
  box.texture = createTexture("box");
  box.texture2 = createTexture("smiley");

  return box;
}
