cmake_minimum_required(VERSION 3.15)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

set(UTILS utils.c utils.h)

add_executable(algorithms ${UTILS} lists/stack.c lists/stack.h)

target_link_libraries(algorithms gc)