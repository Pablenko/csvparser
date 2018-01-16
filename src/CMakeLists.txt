set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -Wall -g")
find_package (Threads)

file(GLOB sources "*.hpp" "*.cpp")

add_executable(csv_parser ${sources})
target_link_libraries(csv_parser ${CMAKE_THREAD_LIBS_INIT} stdc++fs)