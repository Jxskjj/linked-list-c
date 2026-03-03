cmake_minimum_required(VERSION 3.10)
project(LinkedListProject C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(SOURCES
    src/example.c
    src/LinkedList.c
)
set(HEADERS
    inc/LinkedList.h
)

add_executable(linkedlist ${SOURCES} ${HEADERS})
target_include_directories(linkedlist PRIVATE inc)
