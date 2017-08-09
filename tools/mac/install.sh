# !/bin/bash

ROOT_DIR="$(dirname "$0")/../.."
INCLUDE_DIR="${ROOT_DIR}/include"

# https://stackoverflow.com/questions/23450334/opengl-3-3-4-1-on-mac-osx-10-9-using-glfw-library
xcode-select --install
brew update
brew install --without-shared-library glfw3

mkdir "${INCLUDE_DIR}"
curl https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -o "${INCLUDE_DIR}/stb_image.h"
