cmake_minimum_required(VERSION 3.10)
project(LinkedListProject C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(inc)

file(GLOB SOURCES "src/*.c")

add_executable(linkedlist ${SOURCES})
