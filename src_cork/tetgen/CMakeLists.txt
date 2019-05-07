cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)
project(tetgen)

file(
  GLOB tetgen_SRC
  tetgen.cc
  predicates.cxx
  tetgen_interface.cc
  )

set_source_files_properties(
${tetgen_SRC}
PROPERTIES
COMPILER_FLAGS "-Wno-deprecated"
)
add_library(tetgen STATIC ${tetgen_SRC})
# target_compile_definitions(tetgen PRIVATE -DTETLIBRARY)

# Generate position independent code
# set_target_properties(tetgen PROPERTIES POSITION_INDEPENDENT_CODE ON)
# add_executable(tetcall tetcall.cxx)
# target_link_libraries(tetcall PUBLIC tetgen)
