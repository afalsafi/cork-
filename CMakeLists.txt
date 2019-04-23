project (cork64)

cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

include_directories("./")
include_directories("./src")


add_subdirectory("./src/")

add_executable(cork_exe ./src/main.cpp)
target_link_libraries(cork_exe PUBLIC cork64)
