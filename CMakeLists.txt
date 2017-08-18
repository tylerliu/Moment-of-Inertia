cmake_minimum_required(VERSION 3.6)
project(Moment_of_Inertia)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

aux_source_directory(src/ SOURCE_FILES)

add_executable(Moment_of_Inertia ${SOURCE_FILES})