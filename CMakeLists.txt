project (cork64)

cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
# set (CMAKE_STATIC_COMPILER "g++-7)
# set (CMAKE_CC_COMPILER "clang")
set (CMAKE_CC_FLAGS  "-Wall ${INC} -g -fPIC")



# set (CMAKE_CXX_COMPILER "clang++")
set (CMAKE_CXX_FLAGS  "-Wall ${INC} -g -DTETLIBRARY -fPIC")

include_directories("./")
include_directories("./src_cork")


add_subdirectory("./src_cork/")

add_executable(cork_exe ./src_cork/main.cpp)
target_link_libraries(cork_exe PUBLIC corkpp)
