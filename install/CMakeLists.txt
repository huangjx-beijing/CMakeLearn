cmake_minimum_required(VERSION 3.5)

message(STATUS "${CMAKE_VERSION}")

project(installTest)

add_executable(HelloShell main.cpp)

add_library(HelloLib SHARED lib.cpp lib.h)

target_link_libraries(HelloShell HelloLib)

set(CMAKE_INSTALL_PREFIX install/install)

# 3.0
install(CODE "message(STATUS \"********************开始安装********************\")")
install(TARGETS HelloShell HelloLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)
install(CODE "message(STATUS \"********************安装结束********************\")")