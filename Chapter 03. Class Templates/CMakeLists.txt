cmake_minimum_required(VERSION 3.8)
project(Stack1 CXX)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMKAE_CXX_FLAGS "-g -Og -Wall -fcolor-diagnostics -I C:/LLVM/lib/gcc/x86_64-w64-mingw32/7.1.0/include -L C:/LLVM/lib/gcc/x86_64-w64-mingw32/7.1.0/lib --target=x86_64-w64-mingw")
# 指定静态库的位置
# CMAKE_BINARY_DIR代表执行cmake命令的当前目录，比如在build目录下执行则CMAKE_BINARY_DIR代表build
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 指定执行文件位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories("./include")

# 链接库的位置
link_directories(${CMAKE_BINARY_DIR}/lib)

message(warning " this is BINARY dir" ${CMAKE_BINARY_DIR})
message(warning " this is SOURCE dir" ${CMAKE_SOURCE_DIR})

add_executable(Stack1 main.cpp)

# 分离编译
# cd build
# cmake .. -G "MinGW Makefiles"
# mingw32-make