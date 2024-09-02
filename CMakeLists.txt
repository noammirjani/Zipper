cmake_minimum_required(VERSION 3.10)

project(archive VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "src/main.cpp")

add_subdirectory(src)


find_package(spdlog REQUIRED)
find_package(cxxopts REQUIRED)
find_package(LibArchive REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    spdlog::spdlog 
    cxxopts::cxxopts
    LibArchive::LibArchive
    )

