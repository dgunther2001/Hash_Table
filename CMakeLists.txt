cmake_minimum_required(VERSION 3.15)
project(generic_hash_table)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Test files option active..." ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()

