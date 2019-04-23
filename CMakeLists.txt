project (cork64)

cmake_minimum_required (VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

include_directories("./")
include_directories("./accel")
include_directories("./file_formats")
include_directories("./isct")
include_directories("./math")
include_directories("./mpz")
include_directories("./mesh")
include_directories("./rawmesh")
include_directories("./util")
include_directories("./tetgen")
add_subdirectory("./tetgen")
#link mpir. Requires pulling and initializing the submodule
include_directories("./mpir-generic")

#build mpir
add_subdirectory("./mpir-generic")

file(
	GLOB cork_SRC
	"./*.cpp"
	"./*.h"
    "./*.cc"
    "./*.hh"
	"./accel/*.cpp"
	"./accel/*.h"
	"./file_formats/*.cpp"
	"./file_formats/*.h"
	"./isct/*.cpp"
	"./isct/*.c"
	"./isct/*.h"
	"./math/*.cpp"
	"./math/*.h"
	"./mesh/*.cpp"
	"./mesh/*.tpp"
	"./mesh/*.h"
	"./rawmesh/*.cpp"
	"./rawmesh/*.tpp"
	"./rawmesh/*.h"
	"./util/*.cpp"
	"./util/*.h"
    "./tetgen/*.h"
    "./tetgen/*.c"
    "./tetgen/*.hh"
    "./tetgen/*.cc"
)

file(
	GLOB public_headers
	"./*.h"
)

add_definitions(
	-D_USE_MATH_DEFINES 
	-DNOMINMAX 
	-DNO_TIMER
	-DREDUCED
	-DCDT_ONLY
	-DTRILIBRARY
	-DANSI_DECLARATORS
	)

#add_definitions(-DDLLEXPORT)

add_library(cork64 ${cork_SRC})

#link mpir
target_link_libraries(cork64 PUBLIC mpir)

#link tetgen 
target_link_libraries(cork64 PUBLIC tetgen)

#install public facing headers and lib
# install (TARGETS cork64 DESTINATION ${PROJECT_SOURCE_DIR}/lib)
# install (FILES ${public_headers} DESTINATION ${PROJECT_SOURCE_DIR}/include)

add_executable(cork_exe ./main.cpp)
target_link_libraries(cork_exe PUBLIC cork64)
