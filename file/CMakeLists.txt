cmake_minimum_required(VERSION 3.5)

project(fileLearn)

# read/write
file(WRITE test.txt "Hello World")

file(APPEND test.txt " 你好")

file(APPEND test2.h "你好")

file(APPEND test2.cpp "你好")

file(READ test.txt BUFFER LIMIT 5 OFFSET 6)

file(READ test.txt BUFFER_HEX LIMIT 5 OFFSET 6 HEX)

message(STATUS "${BUFFER}")
message(STATUS "${BUFFER_HEX}")

#hash 当前路径
file(MD5 file/test.txt FILE_MD5)
file(SHA1 file/test.txt FILE_SHA1)
file(SHA224 file/test.txt FILE_SHA224)
file(SHA256 file/test.txt FILE_SHA256)
file(SHA384 file/test.txt FILE_SHA384)
file(SHA512 file/test.txt FILE_SHA512)

message(STATUS "${FILE_MD5}")
message(STATUS "${FILE_SHA1}")
message(STATUS "${FILE_SHA224}")
message(STATUS "${FILE_SHA256}")
message(STATUS "${FILE_SHA384}")
message(STATUS "${FILE_SHA512}")

# GLOB 当前cmakelists.txt路径
file(GLOB EMPTY_FILES)
message(STATUS "file GLOB - 不指定任何globbing表达式，返回为空: ${EMPTY_FILES}")

file(GLOB ALL_FILES *.*)
message(STATUS "file GLOB - 使用*.*，返回所有文件: ${ALL_FILES}")

file(GLOB CPP_FILES *.cpp)
message(STATUS "file GLOB - 使用一个globbing表达式，返回指定文件: ${CPP_FILES}")

file(GLOB CPP_H_FILES *.cpp *.h)
message(STATUS "file GLOB - 使用多个globbing表达式，返回多种指定文件: ${CPP_H_FILES}")

file(GLOB SUB_CPP_FILES globtest*/*.cpp )
message(STATUS "file GLOB - 指定路径，返回多种指定文件: ${SUB_CPP_FILES}")

file(GLOB RELATIVE_CPP_FILES RELATIVE E:/huangjx/solution/CMakeLearn/Build *.cpp)
message(STATUS "file GLOB - 指定相对路径，返回相对路径: ${RELATIVE_CPP_FILES}")