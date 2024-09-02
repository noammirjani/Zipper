ROOT=$(pwd)
BUILD_DIR="${ROOT}/build"
PROJECT_NAME="archive"
EXE_PATH="${BUILD_DIR}/${PROJECT_NAME}"

cmake --build ${BUILD_DIR}

#absuote paths
#eval $EXE_PATH compress zip example/test-1 /Users/noammirjani/Documents/projects/Zipper/example/file1.txt /Users/noammirjani/Documents/projects/Zipper/example/file2.txt /Users/noammirjani/Documents/projects/Zipper/example/file3.txt

# relative paths
#eval $EXE_PATH compress rar example/test-2 example/file1.txt example/file2.txt example/file3.txt

#file and directories
eval $EXE_PATH compress zip example/test-2 example/dir4 example/file1.txt

#file dir and compress in it 
#eval $EXE_PATH compress zip example/test-7 example/dir4 example/file1.txt example/test-6.zip


# <action> <type> <resultPath>(relative / nonerelative) <files>(files/directory relate / nonerelative)