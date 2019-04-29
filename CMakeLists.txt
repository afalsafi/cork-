project (cork64)

cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

# set (CMAKE_CC_COMPILER "clang")
set (CMAKE_CC_FLAGS  "-Wall ${INC} -g")


# set (CMAKE_CXX_COMPILER "clang++")
set (CMAKE_CXX_FLAGS  "-Wall ${INC} -g -DTETLIBRARY")

include_directories("./")
include_directories("./src_cork")


add_subdirectory("./src_cork/")

# add_executable(cork_exe ./src_cork/main.cpp)
# target_link_libraries(cork_exe PUBLIC corkpp)
