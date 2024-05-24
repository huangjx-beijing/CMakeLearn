cmake_minimum_required(VERSION 3.5)

project(add_custom_targetLearn)

add_executable(exeTarget main.cpp)

# 空target
add_custom_target(empty)

if(WIN32)
    add_custom_target(dir COMMAND dir /W WORKING_DIRECTORY "C:\\" VERBATIM)

    add_custom_target(ping
        ALL
        COMMAND ping 127.0.0.1
        DEPENDS exeTarget
        COMMENT "欢迎光临Windows Ping 127.0.0.1"
        VERBATIM
        SOURCES custom.txt)
elseif(UNIX)
    add_custom_target(dir COMMAND dir WORKING_DIRECTORY "/" VERBATIM)

    add_custom_target(ping
        ALL
        COMMAND ping 127.0.0.1 -c 4
        DEPENDS exeTarget
        COMMENT "欢迎光临UNIX Ping 127.0.0.1"
        VERBATIM
        SOURCES custom.txt)
endif()