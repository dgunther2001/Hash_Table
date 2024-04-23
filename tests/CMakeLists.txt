project(generic_hash_table)

set(EXECUTABLE_OUTPUT_PATH ../)
add_executable(test ${PROJECT_SOURCE_DIR}/test.cpp)

target_link_libraries(test PRIVATE hash_table)