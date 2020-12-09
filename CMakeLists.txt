cmake_minimum_required(VERSION 3.17)
project(CS2301_HW2 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(CS2301_HW2
        src/CS2301_HW2.c
        src/LinkedList.c
        src/LinkedList.h
        src/marker.c
        src/marker.h
        src/production.c
        src/production.h
        src/space.c
        src/space.h
        src/tests.c
        src/tests.h
        src/TMSName.h)
