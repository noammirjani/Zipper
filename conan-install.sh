#!/bin/bash
WORKING_DIRECTORY=$(pwd)
BUILD_DIRECTORY=${WORKING_DIRECTORY}/build

rm -rf ${BUILD_DIRECTORY}

conan install . --output-folder=build --build=missing -s build_type=Debug

cd build

cmake -S ${WORKING_DIRECTORY} -B ${BUILD_DIRECTORY} -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17
cmake --build . --config Debug