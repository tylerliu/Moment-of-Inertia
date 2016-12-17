cmake_minimum_required(VERSION 3.6)
project(Moment_of_Inertia)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES src/main.c
        src/Execution.h
        src/Execution.c
        src/Instr_set.h
        src/Instr_set.c)
add_executable(Moment_of_Inertia ${SOURCE_FILES})