cmake_minimum_required(VERSION 3.5)

set(HELLOWORLD_HEADER
    HelloWorldGlobal.h
    HelloWorld.h
)

set(HELLOWORLD_CPP
    HelloWorld.cpp
)

include_directories(BEFORE "${CMAKE_SOURCE_DIR}/include")

include_directories(BEFORE "${CMAKE_SOURCE_DIR}/bin")

add_library(HelloWorldLib ${HELLOWORLD_HEADER} ${HELLOWORLD_CPP})

get_target_property(HELLOWORLD_INS HelloWorldLib INCLUDE_DIRECTORIES)

message(STATUS "HelloWorldLib 的包含目录为 ${HELLOWORLD_INS}")

target_include_directories(HelloWorldLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

get_target_property(HELLOWORLD_INS HelloWorldLib INCLUDE_DIRECTORIES)

message(STATUS "HelloWorldLib 的包含目录为 ${HELLOWORLD_INS}")

# 3.0
install(CODE "message(STATUS \"********************开始安装HelloWorldLib********************\")")
install(TARGETS HelloWorldLib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)
install(CODE "message(STATUS \"********************安装结束HelloWorldLib********************\")")