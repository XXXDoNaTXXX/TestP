cmake_minimum_required(VERSION 3.17)
project(TestP)

set(CMAKE_CXX_STANDARD 17)
find_package (Threads REQUIRED)

add_executable(TestP main.cpp log.cpp log.h Writer.h)

target_link_libraries(TestP
        ${CMAKE_THREAD_LIBS_INIT}
        )
