cmake_minimum_required(VERSION 3.5)

add_executable(MyExe main.cpp)

target_include_directories(MyExe PRIVATE $<TARGET_PROPERTY:HelloWorldLib,INTERFACE_INCLUDE_DIRECTORIES>)

target_link_libraries(MyExe PRIVATE HelloWorldLib)


# 3.0
install(CODE "message(STATUS \"********************开始安装MyExe********************\")")
install(TARGETS MyExe
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)
install(CODE "message(STATUS \"********************安装结束MyExe********************\")")