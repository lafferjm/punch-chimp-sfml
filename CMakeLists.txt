cmake_minimum_required(VERSION 3.15)
project(punch-a-chimp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(punch-a-chimp main.cpp)
target_link_libraries(punch-a-chimp sfml-graphics sfml-window sfml-system)
