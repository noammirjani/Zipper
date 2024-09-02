ROOT=$(pwd)
BUILD_DIR="${ROOT}/build"
PROJECT_NAME="archive"
EXE_PATH="${BUILD_DIR}/${PROJECT_NAME}"

cmake --build ${BUILD_DIR}
eval $EXE_PATH compress zip file1.txt file2.txt file3.txt
