cmake_minimum_required(VERSION 3.5)

message(STATUS "${CMAKE_VERSION}")

project(get_filename_component)

set(FILE_ORIGIN "1 1.2.3.4")

# 绝对路径
get_filename_component(FILE_ABSOLUTE ${FILE_ORIGIN} ABSOLUTE)
file(TO_NATIVE_PATH ${FILE_ABSOLUTE} NATIVE_FILE_ABSOLUTE)
message(STATUS "${FILE} 绝对路径: ${FILE_ABSOLUTE}")

# 获取文件的成分
get_filename_component(FILE_DIRECTORY ${FILE_ABSOLUTE} DIRECTORY)
get_filename_component(FILE_NAME_WE ${FILE_ABSOLUTE} NAME_WE)
get_filename_component(FILE_EXT ${FILE_ABSOLUTE} EXT)
get_filename_component(FILE_NAME ${FILE_ABSOLUTE} NAME)

file(TO_NATIVE_PATH ${FILE_DIRECTORY} NATIVE_FILE_DIRECTORY)

message(STATUS "${FILE} 路径: ${FILE_DIRECTORY}")
message(STATUS "${FILE} 文件名(不包括扩展名，也不包括路径): ${FILE_NAME_WE}")
message(STATUS "${FILE} 长扩展名: ${FILE_EXT}")
message(STATUS "${FILE} 文件名(包括扩展名，不包括路径): ${FILE_NAME}")

set(FILE_SYSLINK)
string(APPEND FILE_SYSLINK ${FILE_DIRECTORY})
string(APPEND FILE_SYSLINK "/12.34")

message(STATUS "${FILE} 符号连接: ${FILE_SYSLINK}")

if(WIN32)
    add_custom_target(mksyslinks ALL COMMAND mklink "${FILE_SYSLINK}" "${FILE_ABSOLUTE}")
elseif(UNIX)

endif()

# 真实路径
get_filename_component(FILE_REALPATH ${FILE_SYSLINK} REALPATH)
file(TO_NATIVE_PATH ${FILE_REALPATH} NATIVE_FILE_REALPATH)
message(STATUS "${FILE} 真实路径: ${FILE_REALPATH}")