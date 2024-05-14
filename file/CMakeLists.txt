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