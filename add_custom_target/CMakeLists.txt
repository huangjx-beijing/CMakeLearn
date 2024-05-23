cmake_minimum_required(VERSION 3.5)

project(add_custom_targetLearn)

add_executable(exeTarget main.cpp)

# 空target
add_custom_target(empty)

add_custom_target(dir COMMAND dir /W WORKING_DIRECTORY "D:\\" VERBATIM)

add_custom_target(ping
    ALL
    COMMAND ping 127.0.0.1
    DEPENDS exeTarget
    COMMENT "欢迎光临 Ping 127.0.0.1"
    VERBATIM
    SOURCES custom.txt)