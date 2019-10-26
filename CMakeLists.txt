cmake_minimum_required(VERSION 3.15)
project(punch-a-chimp)

add_executable(punch-a-chimp src/main.cpp)
target_link_libraries(punch-a-chimp sfml-graphics sfml-window sfml-system)
