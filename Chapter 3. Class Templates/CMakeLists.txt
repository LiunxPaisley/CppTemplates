cmake_minimum_required(VERSION 3.8)
project(Stack1 CXX)

set(CMAKE_CXX_STANDARD 17)

# 指定静态库的位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)

# 指定执行文件位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

include_directories("./include")

# 链接库的位置
link_directories(${CMAKE_BINARY_DIR}/build/lib)

message(warning " this is BINARY dir" ${CMAKE_BINARY_DIR})
message(warning " this is SOURCE dir" ${CMAKE_SOURCE_DIR})

add_executable(Stack1 main.cpp)

# cmake --build ./cmake-build  --target Stack1 -- -j 2