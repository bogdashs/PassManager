cmake_minimum_required(VERSION 4.1)
project(PassManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(PassManager main.cpp
)

add_executable(GuardManager GuardManager.cpp)

add_library(utils utils.cpp utils.h)

target_link_libraries(PassManager utils)
target_link_libraries(GuardManager utils)

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")