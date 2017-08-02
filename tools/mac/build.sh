# !/bin/bash

ROOT_DIR="$(dirname "$0")/../.."
ENTRY_FILE="${ROOT_DIR}/source/main.cpp"
OUTPUT_FILE="${ROOT_DIR}/build/main"
ERROR_TEXT="\033[0;31m"
SUCCESS_TEXT="\033[0;32m"
DEFAULT_TEXT="\033[0m"

gcc "${ENTRY_FILE}" -o "${ROOT_DIR}/build/main" -lglfw -framework OpenGL

if [ $? -eq 0 ]; then
  DATE=`date +%H:%M:%S`
  echo "${SUCCESS_TEXT}Built on ${DATE}${DEFAULT_TEXT}"
else
  echo "${ERROR_TEXT}Compilation failed${DEFAULT_TEXT}"
fi
