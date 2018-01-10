cmake_minimum_required (VERSION 2.6)
project (csv_parser)

file(GLOB csv_parser_srcs ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_subdirectory("src/")
add_subdirectory("test/")
