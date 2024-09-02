PROJECT_WORKSPACE := $(shell pwd)
PROJECT_BUILD_DIR_NAME := build
PROJECT_BUILD_PATH := $(PROJECT_WORKSPACE)/$(PROJECT_BUILD_DIR_NAME)
PROJECT_NAME := ZIPPER
EXECUTABLE_PATH := $(PROJECT_BUILD_PATH)/$(PROJECT_NAME)

.PHONY: clean configure build rebuild run build-and-run

clean:
	@rm -rf ${PROJECT_BUILD_PATH}/ && mkdir ${PROJECT_BUILD_PATH}

configure-release:
	@conan install . --output-folder=build --build=missing --settings=build_type=Release
	@cmake -S ${PROJECT_WORKSPACE} -B ${PROJECT_BUILD_PATH} -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

configure-debug:
	@conan install . --output-folder=build --build=missing --settings=build_type=Debug
	@cmake -S ${PROJECT_WORKSPACE} -B ${PROJECT_BUILD_PATH} -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

build: ${PROJECT_WORKSPACE} ${PROJECT_BUILD_PATH}
	@cmake --build ${PROJECT_BUILD_PATH}

build-release: clean configure-release build

build-debug: clean configure-debug build

run:
	@chmod +x ${EXECUTABLE_PATH}
	@echo && ${EXECUTABLE_PATH} && echo

build-and-run: build-release run