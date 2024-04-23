

project(generic_hash_table)

add_library(hash_table SHARED hash_table.cpp)

target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)