cmake_minimum_required(VERSION 3.5)

project(fileLearn)

# read/write
file(WRITE test.txt "Hello World")

file(APPEND test.txt " 你好")

file(APPEND test2.txt "你好")

file(READ test.txt BUFFER LIMIT 5 OFFSET 6)

file(READ test.txt BUFFER_HEX LIMIT 5 OFFSET 6 HEX)

message(STATUS "${BUFFER}")
message(STATUS "${BUFFER_HEX}")