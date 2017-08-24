# !/bin/bash
#
# This isn't being used right now. Apparently it's literally impossible
# to build with a shell and just use xcode to debug. So use the xcode project
# over this.
# https://www.youtube.com/watch?v=lTmM3Y8SMOM

THIS_DIR="$(dirname "$0")"
ROOT_DIR="${THIS_DIR}/../.."
ENTRY_FILE="${ROOT_DIR}/source/main.cpp"
OUTPUT_FILE="${ROOT_DIR}/build/main"
ERROR_TEXT="\033[0;31m"
SUCCESS_TEXT="\033[0;32m"
DEFAULT_TEXT="\033[0m"

rm -f "${OUTPUT_FILE}"
# @TODO: Work out how to include a directory. -I?
# gcc "${ENTRY_FILE}" -o "${ROOT_DIR}/build/main" -lglfw -framework OpenGL "${ROOT_DIR}/source/display.cpp"

# Need to fix working directory for this to be used.
xcodebuild -scheme c-graphics -project "${THIS_DIR}/xcode/c-graphics.xcodeproj" -configuration Debug

if [ $? -eq 0 ]; then
  DATE=`date +%H:%M:%S`
  echo "${SUCCESS_TEXT}Built on ${DATE}${DEFAULT_TEXT}"
else
  echo "${ERROR_TEXT}Compilation failed${DEFAULT_TEXT}"
fi

./${ROOT_DIR}/build/products/Debug/c-graphics
