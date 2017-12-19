### ./CmakeLists.txt
```
cmake_minimum_required(VERSION 3.8)
# 默认定义了两个变量ThreadSync_BINARY_DIR和ThreadSync_SOURCE_DIR
project(ThreadSync CXX) 
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "-g -Wall -static-libgcc -fcolor-diagnostics -std=c++1z --target=x86_64-w64-mingw ")
set(CMAKE_CXX_STANDARD 17)
#add_subdirectory(include include)
#set(SRC "src")
#set(INCLUDE "include")

add_subdirectory(src)
#add_subdirectory(include)

#include_directories(
#        "$(INCLUDE)"
#        "$(INCLUDE)/layers"
#)
# add_subdirectory(src bin)
# set(SOURCE_FILES src/ThreadSync.cpp)
# add_executable(ThreadSync ${SOURCE_FILES})
```

### ./src/CmakeLists.txt
```
# add_subdirectory(layers src/layers)
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 指定静态库位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# 指定执行文件位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 当前目录下代码文件需要的头文件位置
include_directories(
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/include/layers"
)

# 链接库的位置
link_directories(${CMAKE_BINARY_DIR}/lib)

# 添加子文件夹
add_subdirectory(layers)

# 将当前文件夹下的所有文件放入DIR_SRCS变量中
aux_source_directory(. DIR_SRCS)

message(warning " this is BINARY dir" ${CMAKE_BINARY_DIR})
message(warning " this is SOURCE dir" ${CMAKE_SOURCE_DIR})

# 指定可执行文件
add_executable(ThreadSync ${DIR_SRCS})

# 指定可执行文件链接的库
target_link_libraries(ThreadSync layers)
```