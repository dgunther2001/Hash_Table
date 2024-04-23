cmake_minimum_required(VERSION 3.15)
project(generic_hash_table)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_TESTS "Test files option active..." ON)

if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()