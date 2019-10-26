project(punch-a-chimp)

add_library(fist_lib OBJECT sprites/fist/fist.hpp sprites/fist/fist.cpp)

add_executable(punch-a-chimp main.cpp)
target_link_libraries(punch-a-chimp fist_lib sfml-graphics sfml-window sfml-system)
