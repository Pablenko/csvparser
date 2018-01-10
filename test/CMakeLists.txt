cmake_minimum_required (VERSION 2.6)

enable_testing()
find_package(GTest REQUIRED)
find_package (Threads)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB csv_parser_tests_src "*.hpp" "*.cpp")

add_executable(csv_parser_tests ${csv_parser_tests_src})
target_link_libraries(csv_parser_tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(csv_parser_tests ${CMAKE_THREAD_LIBS_INIT})