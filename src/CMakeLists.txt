set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
find_package (Threads)

file(GLOB csv_parser_src "*.hpp" "*.cpp")

add_executable(csv_parser ${csv_parser_src})
target_link_libraries (csv_parser ${CMAKE_THREAD_LIBS_INIT})