cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g")

enable_testing()
find_package(GTest REQUIRED)
find_package (Threads)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB csv_parser_tests_src "*.hpp" "*.cpp")
list(REMOVE_ITEM csv_parser_srcs ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(csv_parser_tests ${csv_parser_srcs} ${csv_parser_tests_src})
target_link_libraries(csv_parser_tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(csv_parser_tests ${CMAKE_THREAD_LIBS_INIT})