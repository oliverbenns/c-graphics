# !/bin/bash
ROOT_DIR="$(dirname "$0")/../.."
ENTRY_FILE="${ROOT_DIR}/source/main.cpp"
OUTPUT_FILE="${ROOT_DIR}/build/main"

gcc "${ENTRY_FILE}" -o "${OUTPUT_FILE}"

DATE=`date +%H:%M:%S`
echo "Built on ${DATE}"
