cmake_minimum_required(VERSION 3.5)

message(STATUS "${CMAKE_VERSION}")

project(installTest)

add_definitions(-DBUILD_HELLOWORLD_LIB)

if(WIN32)
    add_definitions(-DHELLOWORLD_WIN)
endif()

if(BUILD_SHARED_LIBS)
    add_definitions(-DBUILD_SHARED)
endif()

add_subdirectory(HelloWorld)

add_subdirectory(MyExe)