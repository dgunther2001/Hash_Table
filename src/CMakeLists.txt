project(generic_hash_table)


#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build)

#set(CMAKE_CXX_FLAGS "-c")

add_library(hash_table SHARED hash_table.cpp)


target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

#target_link_libraries(hash_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})