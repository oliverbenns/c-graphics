# !/bin/bash

# https://stackoverflow.com/questions/23450334/opengl-3-3-4-1-on-mac-osx-10-9-using-glfw-library
xcode-select --install
brew update
brew install --without-shared-library glfw3
