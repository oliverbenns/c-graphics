# !/bin/bash

ROOT_DIR="$(dirname "$0")/../.."
INCLUDE_DIR="${ROOT_DIR}/include"
TEMP_DIR="${ROOT_DIR}/temp"

# SETUP
rm -rf "${TEMP_DIR}/*"
mkdir "${INCLUDE_DIR}"
mkdir "${TEMP_DIR}"

# COMPILER / XCODE
xcode-select --install

# GLFW
# https://stackoverflow.com/questions/23450334/opengl-3-3-4-1-on-mac-osx-10-9-using-glfw-library
brew update
brew install --without-shared-library glfw3

# STB_IMAGE
mkdir "${INCLUDE_DIR}"
curl https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -o "${INCLUDE_DIR}/stb_image.h"

# GLM
GLM_VERSION="0.9.8.5"
GLM_ZIP="${TEMP_DIR}/${GLM_VERSION}.zip"

curl -L "https://github.com/g-truc/glm/archive/${GLM_VERSION}.zip" -o "$GLM_ZIP"
unzip "$GLM_ZIP" -d "${TEMP_DIR}"
rm -rf "${INCLUDE_DIR}/glm"
mv "${TEMP_DIR}/glm-${GLM_VERSION}/glm" "${INCLUDE_DIR}"

# CLEANUP
rm -rf "${TEMP_DIR}"
