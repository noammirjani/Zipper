cmake_minimum_required(VERSION 3.10)

project(ZIPPER VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZIPPER src/main.cpp)

find_package(spdlog REQUIRED)
target_link_libraries(ZIPPER PRIVATE spdlog::spdlog)
