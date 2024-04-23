project(generic_hash_table)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -target x86_64-apple-darwin")

set(EXECUTABLE_OUTPUT_PATH ../)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#find_library(HASH_TABLE_LIBRARY NAMES hash_table PATHS ../build/src)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE hash_table)

#target_link_libraries(test PRIVATE ${CMAKE_BINARY_DIR}/hash_table.dylib )




