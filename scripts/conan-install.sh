#!/bin/bash
ROOT_DIR=$(pwd)
BUILD_DIR="${ROOT_DIR}/build"

rm -rf ${BUILD_DIR}

conan install . --output-folder=${BUILD_DIR} --build=missing -s build_type=Debug

cd ${BUILD_DIR}

cmake .. -DCMAKE_TOOLCHAIN_FILE=build/Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17
cmake --build .